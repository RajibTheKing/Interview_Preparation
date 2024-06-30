class Solution {
public:
    int maxProfit(vector<int>& prices) {
        deque<int> dq;
        int sum = 0;
        for(int i=prices.size()-1; i>=0; i--)
        {
            if(dq.empty())
            {
                dq.push_front(prices[i]);
            }
            else if(prices[i] <= dq.front())
            {
                dq.push_front(prices[i]);
            }
            else
            {
                sum += dq.back() - dq.front();
                dq.clear();
                dq.push_front(prices[i]);
            }

        }
        if(dq.size() > 1)
        {
            sum += dq.back() - dq.front();
        }
        return sum;
    }
};

