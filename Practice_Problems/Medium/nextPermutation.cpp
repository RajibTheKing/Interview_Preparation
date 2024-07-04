class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n = nums.size();
        
        int breakIndex = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i+1])
            {
                breakIndex = i;
                break;
            }
        }

        if (breakIndex == -1)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            int maxValueIndex = -1;
            for (int i = n - 1; i >= breakIndex; i--)
            {
                if (nums[breakIndex] < nums[i])
                {
                    maxValueIndex = i;
                    swap(nums[breakIndex], nums[maxValueIndex]);
                    reverse(&nums[breakIndex+1], &nums[n]);
                    break;
                }
            }
        }
    }
};

// 4 5 6 7 8 9 1 2 2
// 4 5 6 7 8 9 2 1
// 1 3 4 2

