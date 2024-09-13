#include <iostream>
#include <map>
#include <string>


using namespace std;

int main()
{
    map<int, string> mp;

    mp[3] = "hello";
    mp[10] = "world";
    mp[4] = "yes";
    mp[11] = "now";
    mp[2] = "fowl";

    for(const auto& x : mp)
    {
        cout << x.first <<", " << x.second << endl;
    }

}