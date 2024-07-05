class Solution {
public:
    int color[12];
    map<int, bool> mp;

    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        memset(color, -1, sizeof(color));
        solve(0, nums);
        return ans;
    }

    void solve(int cur, vector<int>& nums)
    {
        if (cur == nums.size())
        {
            vector<int> ret(nums.size());
            long long sum = 1;

            for (int i = 0; i < nums.size(); i++)
            {
                ret[i] = nums[color[i]];
                sum *= 100;
                sum += (ret[i] + 10);
            }
            if (mp.find(sum) == mp.end())
            {
                mp[sum] = false;
                ans.push_back(ret);
            }

            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (color[i] == -1)
            {
                color[i] = cur;
                solve(cur+1, nums);
                color[i] = -1;
            }
        }
    }

};