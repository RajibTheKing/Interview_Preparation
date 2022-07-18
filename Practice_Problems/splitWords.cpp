#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    stringstream ss;
    string str = "i want to say one more thing";
    ss<<str;
    string word;
    while(ss>>word){
        cout<<word<<endl;
    }
    
    return 0;
}

