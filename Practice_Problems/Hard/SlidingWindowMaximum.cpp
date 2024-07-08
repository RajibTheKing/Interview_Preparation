class Collection
{
public:
    map<int, int> mp;
    set<int> uniqueNumbers;
    Collection()
    {
        mp.clear();
        uniqueNumbers.clear();
    }

    void insert(int num)
    {
        if (mp.find(num) == mp.end())
        {
            mp[num] = 1;
        }
        else
        {
            mp[num]++;
        }
        uniqueNumbers.insert(num);
    }

    void erase(int num)
    {
        mp[num]--;
        if (mp[num] <= 0)
        {
            uniqueNumbers.erase(num);
        }
    }

    int getMax()
    {
        auto it = uniqueNumbers.end();
        it--;
        return *it;
    }
};
class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        Collection list;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i >= k)
            {
                ret.push_back(list.getMax());
                list.erase(nums[i-k]);
            }
            list.insert(nums[i]);
        }
        ret.push_back(list.getMax());
        return ret;
    }
};