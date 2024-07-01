class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vowels;

        for (const auto& c : s)
        {
            if (isVowel(c))
                vowels.push_back(c);
        }

        for (int i = s.size() - 1, j = 0; i >= 0; i--)
        {
            if (isVowel(s[i]))
            {
                s[i] = vowels[j++];
            }
        }
        return s;
    }

    bool isVowel(char c)
    {
        c = tolower(c);
        return c == 'a' | c == 'e' | c == 'i' | c == 'o' | c == 'u';
    }
};