#include <iostream>
#include <queue>

using namespace std;


class Compare
{
public:
    bool operator () (const int& current, const int& other)
    {
        //return current > other; //min heap
        return current < other; //max heap

        //How to remember?
        // If considering "other" as smaller then it's min heap
        // If considering "other" as bigger then it's max heap
    }
};


int main()
{
    priority_queue<int, vector<int>, Compare> pq;

    pq.push(1);
    pq.push(6);
    pq.push(3);

    while(!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}