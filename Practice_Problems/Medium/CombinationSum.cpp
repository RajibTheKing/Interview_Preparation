class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<int> temp;
        solve(candidates, target, temp, 0, 0);;
        return ans;
    }

    void solve(vector<int>& candidates, int target, vector<int> currComb, int currSum, int currIndex)
    {
        if (currSum > target)
            return;

        if (currSum == target)
        {
            ans.push_back(currComb); //store the solution
            return;
        }

        for (int i = currIndex; i < candidates.size(); i++)
        {
            currComb.push_back(candidates[i]);
            currSum += candidates[i];
            solve(candidates, target, currComb, currSum, i);
            currComb.pop_back();
            currSum -= candidates[i];
        }
    }
};

// 2 3 6 7 : target: 12

//      2           3        6       7
 
// 2  3  6  7    2 3 6 7    2 3 6   2 3

