#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

std::string decimalToBinary(unsigned int num)
{
    if (num == 0) return "0";

    size_t totalBits = floor(log2(num) + 1);
    std::string result;
    result.resize(totalBits);

    for(int i = totalBits - 1; i >= 0; i--)
    {
        result[i] = num % 2 == 0 ? '0' : '1';
        num /= 2;
    }
    return result;
}

vector<vector<int>> mergeTwoVector(vector<vector<int>> a, vector<vector<int>> b)
{
    copy(a.begin(), a.end(), back_inserter(b));
    return b;
}

int color[10];

vector<vector<int>> generate_perm(int cnt, int indx, vector<int>& arr)
{
    // base condition
    if (cnt >= arr.size())
    {
        vector<int> now;
        vector<vector<int>> ans;
        for (int i = 0; i < arr.size(); i++)
        {
            now.push_back(arr[color[i]]);
            cout << "Here: " << now[i] << " ";
        }
        cout << endl;
        ans.push_back(now);
        return ans;
    }

    vector<vector<int>> result;
    for (int i = 0; i < arr.size(); i++)
    {
        if (color[i] == -1)
        {
            color[i] = indx;
            result = mergeTwoVector(generate_perm(cnt+1, indx+1, arr), result);
            color[i] = -1;
        }
    }

    return result;
}

int main()
{
    for(unsigned int i=0; i<=32; i++)
    {
        std::cout << i << " --> " << decimalToBinary(i) << ", logVal = " <<  log2(i) << std::endl;
    }

    memset(color, -1, sizeof(color));
    vector<int> arr = {5, 4, 8, 6};
    vector<vector<int>> ans = generate_perm(0, 0, arr);
    for (int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    vector<int> a = {1, 2, 3};
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = i;
    }

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}
