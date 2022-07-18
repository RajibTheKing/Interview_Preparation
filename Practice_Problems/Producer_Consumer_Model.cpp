#include <iostream>
#include <exception>
#include <algorithm>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <string.h>

using namespace std;

condition_variable cv;
bool g_ready = false;

class RingBuffer
{
private:
    int maxBufferSize;
    int front;
    int rear;
    int *buffer;
    int numberOfElement;
    mutex buffer_mutex;
public:
    RingBuffer(int capacity){
        maxBufferSize = capacity;
        buffer = new int[capacity];
        memset(buffer, -1, sizeof(int)*capacity);
        front = -1;
        rear = -1;
        numberOfElement = 0;
    }

    ~RingBuffer(){
        delete buffer;
    }

    void push(int newVal){
        const std::lock_guard<std::mutex> lock(buffer_mutex);   
        if(numberOfElement == 0){
            //currently no values inside buffer
            front = 0;
            rear = 0;
            buffer[rear] = newVal;
            rear = (rear + 1) % maxBufferSize;

        }else if(numberOfElement == maxBufferSize){
            //currently buffer is full
            buffer[rear] = newVal;
            front = (front + 1) % maxBufferSize;
            rear = (rear + 1) % maxBufferSize;
        }else{
            //currently buffer has some data but not full
            buffer[rear] = newVal;
            rear = (rear + 1) % maxBufferSize;
        }
        numberOfElement = min(maxBufferSize, numberOfElement+1);

    }

    int pop(){
        const std::lock_guard<std::mutex> lock(buffer_mutex);
        if(numberOfElement != 0)
        {
            int now = buffer[front];
            buffer[front] = -1; //deleting this value
            front = (front + 1) % maxBufferSize;
            numberOfElement = max(0, numberOfElement-1);
            return now;
        }else{
            cout<<"POP failed, Buffer is Empty"<<endl;
            return -1;
        }

    }

    bool isEmpty(){
        const std::lock_guard<std::mutex> lock(buffer_mutex);
        if(numberOfElement <= 0){
            return true;
        }
        return false;
    }

    void print_buffer(){
        cout<<"Buffer: ";
        for(int i=0; i<maxBufferSize; i++){
            cout<<buffer[i]<<" ";
        }
        cout<<" ---> Front: "<<front<<" and Rear: "<<rear<<" --- numberOfElments: "<< numberOfElement <<endl;
    }

};


class Producer{
private:
    RingBuffer *buf = nullptr;
    thread *producerThread;
public:
    
    Producer(RingBuffer *buffer){
        buf = buffer;
        producerThread = new thread(&startProcessing, this);
    }

    void startProcessing(){

        while(true){
            int randomValue = rand()%10 + 1;
            cout<<"Push: "<<randomValue<<endl;
            buf->push(randomValue);
            buf->print_buffer();
            g_ready = !buf->isEmpty();
            if(g_ready){
                cv.notify_one();
            }
            this_thread::sleep_for(1000ms);
            
        }

    }

};

class Consumer {
private:
    RingBuffer *buf = nullptr;
    thread *consumerThread;
    mutex c_mutex;
public:
    
    Consumer(RingBuffer *buffer){
        buf = buffer;
        consumerThread = new thread(&startProcessing, this);
    }

    void startProcessing(){

        while(true){
            std::unique_lock<std::mutex> ul(c_mutex);
            cv.wait(ul, [](){return g_ready;});

            int now = buf->pop();
            cout<<"Pop: "<<now<<endl;
            buf->print_buffer();
            g_ready = !buf->isEmpty();
            //this_thread::sleep_for(1500ms);
            
        }

    }

};

int main()
{
    RingBuffer *buf = new RingBuffer(5);
    Producer *producer = new Producer(buf);
    Consumer *consumer = new Consumer(buf);

    while(true){
        cout<<"This is main Thread"<<endl;
        this_thread::sleep_for(2000ms);
    }

    
    return 0;
}