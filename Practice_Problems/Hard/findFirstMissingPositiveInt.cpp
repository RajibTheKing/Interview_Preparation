class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int searchValue = 1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= 0)
                continue;
            else
                if (nums[i] != searchValue)
                    return searchValue;
                else
                    while(i < n && nums[i] == searchValue)
                        i++;
                    i--;
                    searchValue++;
        }
        return searchValue;
    }
};


