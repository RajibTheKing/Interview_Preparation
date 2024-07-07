class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        vector<string> ret;
        int startingPos = 0;
        int remainingLength = maxWidth;

        for (int i = 0; i < words.size(); i++)
        {
            if (remainingLength == maxWidth)
            {
                startingPos = i;
                remainingLength-= words[i].size();
                continue;
            }

            if (1 + words[i].size() > remainingLength)
            {
                i--;
                string now = justify(startingPos, i, maxWidth, words);
                ret.push_back(now);
                remainingLength = maxWidth;
            }
            else
            {
                remainingLength -= (1 + words[i].size());
            }
        }

        string now = justify(startingPos, words.size()-1, maxWidth, words);
        ret.push_back(now);
        return ret;
    }

    string justify(int startingPos, int endingPos, int& maxWidth, vector<string>& words)
    {
        std::string ans(maxWidth, ' ');
        if (startingPos == endingPos)
        {
            std::memcpy(&ans[0], &words[startingPos][0], words[startingPos].size());
        }
        else if (endingPos == words.size() - 1)
        {
            // handle last line
            int ansPos = 0;
            for (int i = startingPos; i <= endingPos; i++)
            {
                if (i != startingPos)
                    ansPos++;

                std::memcpy(&ans[ansPos], &words[i][0], words[i].size());
                ansPos += words[i].size();
            }
        }
        else
        {
            int slots = endingPos - startingPos;
            int currentLength = 0;
            for(int i = startingPos; i <= endingPos; i++)
            {
                currentLength += words[i].size();
            }

            int remainingLength = maxWidth - currentLength;
            int extraSpace = 0;
            int mustSpace = remainingLength / slots;
            if (remainingLength % slots != 0)
            {
                extraSpace = remainingLength - (slots * mustSpace);
            }

            int ansPos = 0;
            for(int i = startingPos; i <= endingPos; i++)
            {
                std::memcpy(&ans[ansPos], &words[i][0], words[i].size());
                ansPos += words[i].size();
                ansPos += mustSpace;
                if (extraSpace)
                {
                    ansPos++;
                    extraSpace--;
                }
            }
        }
        return ans;
    }
};