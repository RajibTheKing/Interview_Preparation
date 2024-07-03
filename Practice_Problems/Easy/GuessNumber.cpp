/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        return solve(1, n);
    }

    int solve(long long left, long long right)
    {
        if (left > right)
        {
            return -1;
        }

        long long mid = (left + right) / 2;
        int now = guess(mid);

        if (now == -1)
        {
            // I guessed higher
            return solve(left, mid-1);
        }
        else if (now == 1)
        {
            // I guessed lower
            return solve(mid+1, right);
        }
        else
        {
            return mid;
        }
    }
};