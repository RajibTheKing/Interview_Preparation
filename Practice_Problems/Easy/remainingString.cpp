class Solution {
  public:

    string printString(string s, char ch, int count) {
        // Your code goes here
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ch)
            {
                count--;
            }

            if (count == 0)
            {
                return s.substr(i+1, s.size() - i - 1);
            }
        }
        return "";
    }
};