class Solution {
public:
    map<char, int> mp;
    string minWindow(string s, string t) 
    {
        
        if (s.empty() || t.empty() || s.length() < t.length()) 
        {
            return "";
        }

        std::vector<int> map(128, 0);
        int count = t.length();
        int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;
        
        for (char c : t) {
            map[c]++;
        }

        while (end < s.length())
        {
            if (map[s[end++]]-- > 0)
            {
                count--;
            }

            while (count == 0) 
            {
                if (end - start < minLen)
                {
                    startIndex = start;
                    minLen = end - start;
                }

                if (map[s[start++]]++ == 0)
                {
                    count++;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};

// A : 1
// B : 1
// C : 1

// A D O B E  C O D E B A N C
// 0 1 2 3 4  5 6 7 8 9 0 1 2

// A : 2
// D : 2
// O : 2
// B : 2
// E : 2
// C : 2
// N : 1

// minAns = 0, 12

// A : 1
// D : 0
// O : 0
// B : 1
// E : 0
// C : 1
// N : 1

