class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
        {
            return "1";
        }
        return encodeToRLE(countAndSay(n-1));
    }

    string encodeToRLE(string s)
    {
        //expecting s will not be empty

        int count = 1;
        char c = s[0];
        string ans = "";
        for (int i = 1; i < s.size(); i++)
        {
            if (c == s[i])
            {
                count++;
            }
            else
            {
                ans += (to_string(count)+c);
                count = 1;
                c = s[i];
            }
        }
        ans += (to_string(count)+c);

        return ans;
    }
};