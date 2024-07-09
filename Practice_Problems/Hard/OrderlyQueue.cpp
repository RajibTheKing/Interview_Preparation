class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 0)
            return s;
        else if (k == 1)
        {
            char minChar = 'z';
            for (const auto& c : s)
                minChar = min(minChar, c);

            vector<string> collection;

            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == minChar)
                {
                    // this might be a possible
                    string part1 = s.substr(0, i);
                    string part2 = s.substr(i, s.size() - i);
                    string newString = part2 + part1;
                    collection.push_back(newString);
                }
            }
            sort(collection.begin(), collection.end());
            return collection[0];
        }
        else
        {
            sort(s.begin(), s.end());
            return s;
        }
    }
};

// axycbz, k = 1
//         k = 2

// axycbz k = 2
//     -> aycbzx
//         -> acbzxy
//             ->abzxyc