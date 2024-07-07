class Solution {
public:
    int calculate(string s) 
    {
        stack<int> st;
        int sign = 1;
        int pos = 0;
        int ans = 0;

        while(pos < s.size())
        {
            string token = nextToken(pos, s);
            if (token.size() == 0)
            {
                break;
            }

            if (token[0] == '(')
            {
                st.push(ans);
                st.push(sign);
                ans = 0;
                sign = 1;
            }
            else if (token[0] == '+')
                sign = 1;
            else if (token[0] == '-')
                sign = -1;
            else if (token[0] == ')')
            {
                ans *= st.top(); st.pop();
                ans += st.top(); st.pop();
            }
            else
            {
                int num = stoi(token);
                num *= sign;
                ans += num;
            }
        }

        return ans;
    }

    string nextToken(int& pos, string& s)
    {
        while(s[pos] == ' ')
            pos++;

        string token = "";
        if (pos >= s.size())
        {
            return token;
        }

        if(s[pos] == '(' || s[pos] == ')' || s[pos] == '+' || s[pos] == '-')
        {
            token += s[pos++];
        }
        else
        {
            while(pos < s.size() && s[pos] >= '0' && s[pos] <= '9')
            {
                token += s[pos];
                pos++;
            }
        }
        return token;
    }

};