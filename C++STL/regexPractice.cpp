#include <iostream>
#include <iterator>
#include <regex>
#include <string>
using namespace std;

bool check_cases(vector<string>& maching_cases, string& regex_str)
{
    regex re(regex_str);
    for (const auto& str : maching_cases)
    {
        bool result = std::regex_match(str, re);
        cout << "Matching : " << str << ", " << regex_str << " --> Result : " << result << endl;
        if (result == false)
        {
            return false;
        }
    }
    return true;
}

bool TestCase_AnyCharacter(string& regex_str)
{
    vector<string> maching_cases = {"abcdefg", "abcde", "abc"};
    return check_cases(maching_cases, regex_str);
}

int main()
{
    string regex_str;

    regex_str = ".*";
    cout << TestCase_AnyCharacter(regex_str) << endl << endl << endl;
}