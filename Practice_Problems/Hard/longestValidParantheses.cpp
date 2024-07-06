class Solution {
public:
    int longestValidParentheses(string s) 
    {
        return maxValidParantheses(0, s);
    }

    int maxValidParantheses(int startingPos, string& s)
    {
        stack<int> st;
        st.push(-1);
        int maxCnt = 0;

        for (int i = startingPos; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (st.empty())
                    st.push(i);

                maxCnt = max(maxCnt, i - st.top());
            }
        }
        return maxCnt;
    }
};