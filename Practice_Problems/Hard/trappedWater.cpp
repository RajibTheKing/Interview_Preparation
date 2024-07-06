class Solution {
public:
    int trap(vector<int>& height) {
        int maxHeight = 0;
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);

        // from each i, store maximum height seen on left so far
        left[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], height[i]);
        }

        // similarly for each i, store maximum height seen on right so far
        right[n-1] = height[n-1];
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(right[i + 1], height[i]);
        }

        // now calculate trapped water easily
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int minHeight = min(left[i], right[i]);
            ans += (minHeight - height[i]);
        }
        return ans;
    }
};



//          |
//     |....|
//     |..|.|
//     ||.|||
//     ||.|||
//     ------
// level 1: 1
// level 2: 1
// level 3: 3
// level 4: 4
// level 5: 0


