#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> getWordList(string sentence){
    vector<string> ans;
    ans.clear();
    stringstream ss;
    ss<<sentence;
    string word;
    while(ss>>word){
        ans.push_back(word);
    }

    return ans;
}



int main()
{
    string sentence = "i want to say one more thing";
    vector<string> wordList = getWordList(sentence);

    cout<<"WordList for Sentence: '"<<sentence<<"' ===> ['";
    for(auto x: wordList){
        cout<<x<<"', '";
    }
    cout<<"]"<<endl;

    cout<<sentence.substr(2)<<endl;
    if(sentence.find("i") != string::npos){
        cout<<sentence.find("i")<<endl;
    }

    return 0;
}

