class Solution {
public:
    bool isPerfectSquare(int num) {
        return solve(1, 46340, num);
    }

    bool solve(int left, int right, int num)
    {
        if (left > right)
            return false;
        int mid = (right + left) / 2;
        //cout << left << ", " << right << ", mid = " << mid << endl;

        if (mid * mid == num)
            return true;

        if (mid * mid < num)
            return solve(mid + 1, right, num);
        else
            return solve(left, mid - 1, num);
    }
};