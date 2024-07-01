class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> mp;
        vector<int> tempArray;
        for (const auto& x : nums)
        {
            if (mp.find(x) == mp.end())
            {
                mp[x] = 1;
                tempArray.push_back(x);
            }
            else
            {
                mp[x] ++;
            }
        }

        int k = tempArray.size();
        for(int i=0; i<k; i++)
        {
            nums[i] = tempArray[i];
        }
        return k;
    }
};