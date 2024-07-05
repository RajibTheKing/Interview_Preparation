class Solution {
public:
    vector<vector<int>> ans;
    map<int, int> counter;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size(); i++)
        {
            if (counter.find(candidates[i]) == counter.end())
            {
                counter[candidates[i]] = 1;
            }
            else
            {
                counter[candidates[i]]++;
            }
        }

        vector<int> currComb;

        solve(candidates, target, currComb, 0, 0);
        return ans;
    }

    void solve(vector<int>& candidates, int target, vector<int> currComb, int currSum, int currIndex)
    {
        //cout << target << ", currSum = " << currSum << ", " << currIndex << endl;


        if (currSum > target)
            return;

        if (currSum == target)
        {
            ans.push_back(currComb); //store the solution
            return;
        }

        if (currIndex >= candidates.size())
            return;

        int cnt = counter[candidates[currIndex]];
        vector<int> newComb;
        int newCurSum = currSum;

        for (int i = 0; i < cnt; i++)
        {
            newComb.push_back(candidates[currIndex]);
            copy(newComb.begin(), newComb.end(), back_inserter(currComb));
            newCurSum += candidates[currIndex];
            solve(candidates, target, currComb, newCurSum, currIndex+cnt);

            for (int j = 0; j < newComb.size(); j++)
            {
                currComb.pop_back();
            }
        }
        solve(candidates, target, currComb, currSum, currIndex+cnt);
    }
};

// 1 2 2 2 5