class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> arr(m + n);
        int index = 0;
        int ptr1 = 0;
        int ptr2 = 0;
        while (ptr1 < m && ptr2 < n)
        {
            if(nums1[ptr1] <= nums2[ptr2])
            {
                arr[index++] = nums1[ptr1];
                ptr1++;
            }
            else
            {
                arr[index++] = nums2[ptr2];
                ptr2++;
            }
        }

        while (ptr1 < m)
            arr[index++] = nums1[ptr1++];

        while (ptr2 < n)
            arr[index++] = nums2[ptr2++];

        for (int i = 0; i < (m+n); i++)
            nums1[i] = arr[i];
    }
};