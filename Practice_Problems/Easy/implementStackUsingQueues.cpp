class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int lastValue;
        while(q1.size() != 1)
        {
            lastValue = q1.front(); q1.pop();
            q2.push(lastValue);
        }
        
        lastValue = q1.front();
        q1.pop();

        while(!q2.empty())
        {
            int x = q2.front(); q2.pop();
            q1.push(x);
        }

        return lastValue;
    }

    int top() {
        int x = pop();
        push(x);
        return x;
    }

    bool empty() {
        return q1.empty() & q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */