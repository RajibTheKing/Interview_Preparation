class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int left = 0;
        int right = arr.size() - 1;

        while (arr[left] == 0)
            left++;

        while (arr[right] == 1)
            right--;

        while (left < right)
        {
            swap(arr[left], arr[right]);

            while (arr[left] == 0)
                left++;

            while (arr[right] == 1)
                right--;
        }
    }
};