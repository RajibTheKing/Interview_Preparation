class Number
{
public:
    int value;
    int frequency;
    Number(int v, int f)
    {
        value = v;
        frequency = f;
    }
};

class Solution {
public:
    static bool compareFunc(Number a, Number b)
    {
        return a.frequency < b.frequency;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> mp;
        int result = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (mp.find(arr[i]) == mp.end())
            {
                result++;
                mp[arr[i]] = 1;
            }
            else
            {
                mp[arr[i]]++;
            }
        }

        vector<Number> num;
        for (const auto& cur : mp)
        {
            num.push_back(Number(cur.first, cur.second));
        }

        sort(num.begin(), num.end(), compareFunc);

        for (int i = 0; i < num.size(); i++)
        {
            if (num[i].frequency > k)
            {
                return result;
            }
            else if (num[i].frequency == k)
            {
                return result - 1;
            }
            else
            {
                k = k - num[i].frequency;
                result --;
            }
        }

        return result;
    }
};