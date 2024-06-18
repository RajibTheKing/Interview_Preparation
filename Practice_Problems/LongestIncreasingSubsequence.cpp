#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dp[100][100];

//O(2^n) --> now it's O(N * N) after memoisition
//it's my method

int solve(int cur, int prev_index, vector<int> &arr)
{
    //base case:
    if(cur == arr.size())
    {
        return 0;
    }

    int &ret = dp[cur][prev_index + 1];

    if(ret != -1)
    {
        return ret;
    }

    ret = INT_MIN;

    if(prev_index < 0 || arr[cur] > arr[prev_index])
    {
        // we can take this
        ret = max(ret, 1 + solve(cur+1, cur, arr));
    }
        // or we don't take this
    ret = max(ret, solve(cur+1, prev_index, arr));

    return ret;

}

int solveBottomUp(vector<int>& arr)
{
    int lis[100];
    int result = 1;
    lis[0] = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        lis[i] = 1;
        for (int j=0; j<i; j++)
        {
            if (arr[i] > arr[j])
            {
                lis[i] = max(lis[i], 1 + lis[j]);
                result = max(result, lis[i]);
            }
        }
    }

    return result;
}

int main()
{
    vector<int> arr = {10, 2, 6, 10, 5, 4, 7, 11, 3, 13};
    for (int i=0; i <= arr.size(); i++)
    {
        for (int j=0; j <= arr.size(); j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << solve(0, -1, arr) << endl;
    cout << solveBottomUp(arr) << endl;
    return 0;
}
