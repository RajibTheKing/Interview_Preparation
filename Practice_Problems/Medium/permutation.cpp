class Solution {
public:
    int color[12];
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        memset(color, -1, sizeof(color));
        solve(0, nums);
        return ans;
    }

    void solve(int cur, vector<int>& nums)
    {
        if (cur == nums.size())
        {
            vector<int> ret(nums.size());
            for (int i = 0; i < nums.size(); i++)
            {
                ret[i] = nums[color[i]];
            }
            ans.push_back(ret);
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