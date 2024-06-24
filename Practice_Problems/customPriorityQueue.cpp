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

1, 1
4, 5
4, 7
7, 9
11, 12
9, 13
14, 14
16, 16
16, 16
16, 17
16, 18
17, 18
19, 19
18, 20
20, 21
19, 23
21, 23
22, 25
25, 26
25, 26
24, 28


1, 1
4, 5
5, 7
7, 9
11, 12
9, 13
14, 14
16, 16
17, 16
18, 17
17, 18
19, 18
19, 19
18, 20
20, 21
19, 23
21, 23
22, 25
25, 26
26, 26
24, 28