class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int sum;
        int minDistance = INT_MAX;
        int ans;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    sum = nums[i] + nums[j] + nums[k];
                    int distance = max(target, sum) - min(target, sum);
                    if (distance < minDistance)
                    {
                        minDistance = distance;
                        ans = sum;
                    }
                }
            }
        }

        return ans;
    }
};