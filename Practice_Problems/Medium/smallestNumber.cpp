class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        return to_string(solve(0, d, s));
    }

    int solve(int cur, int d, int target)
    {
        if (cur == d - 1 && target > 9)
        {
            return -1;
        }

        if (cur == d - 1 && target <= 9)
        {
            return target;
        }

        int startingDigit = cur == 0 ? 1 : 0;
        for ( ; startingDigit <= 9; startingDigit++)
        {
            int next = solve(cur+1, d, target-startingDigit);
            if (next != -1)
            {
                return startingDigit * pow(10, d-cur-1) + next;
            }
        }

        return -1;
    }
};