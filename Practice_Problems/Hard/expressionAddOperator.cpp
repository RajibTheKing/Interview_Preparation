class Solution {
public:
    vector<string> ans;
    vector<string> addOperators(string num, int target) {
        solve(num, 0, "", 0, 0, target);
        return ans;
    }

    void solve(string& num, int pos, string path, long long result, long long prevNum, long long target)
    {
        //cout << path << ", " << result << ", " << target << endl;

        if (pos >= num.size())
        {
            if (result == target)
                ans.push_back(path);
            return;
        }

        string currentNumStr = "";
        long long now;

        for (int i = pos; i < num.size(); i++)
        {
            if (i > pos && num[pos] == '0') break;
            currentNumStr += num[i];
            now = stoll(currentNumStr);
            if (path.size() == 0)
            {
                solve(num, i+1, currentNumStr, now, now, target);
            }
            else
            {
                solve(num, i+1, path + "+" + currentNumStr, result + now, now, target);
                solve(num, i+1, path + "-" + currentNumStr, result - now, -now, target);
                solve(num, i+1, path + "*" + currentNumStr, result - prevNum + prevNum * now, prevNum * now, target);
            }
        }
    }
};
