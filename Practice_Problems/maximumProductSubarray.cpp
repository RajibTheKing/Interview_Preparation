class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // kadan's algorithm
        
        int n = nums.size(); 
        double maxProduct = max(nums[0], nums[n-1]);
        vector<double> left(n);
        vector<double> right(n);

        left[0] = nums[0];
        for(int i=1; i<n; i++)
        {
            if(left[i-1] == 0)
            {
                left[i] = nums[i];
            }
            else
            {
                left[i] = left[i-1] * nums[i];
            }
            maxProduct = max(maxProduct, left[i]);
        }

        right[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--)
        {
            if(right[i+1] == 0)
            {
                right[i] = nums[i];
            }
            else
            {
                right[i] = right[i+1] * nums[i];
            }
            maxProduct = max(maxProduct, right[i]);
        }
        return (int)maxProduct;
    }
};
