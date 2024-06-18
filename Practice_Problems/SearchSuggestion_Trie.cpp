#include <iostream>
#include <vector>
#include <string>
using namespace std;


#define SZ 26
class Solution
{
public:
    class Trie
    {
    public:
        Trie *children[SZ];
        bool isEndingNode;
        Trie()
        {
            for (int i = 0; i < SZ; i++)
                children[i] = nullptr;
            isEndingNode = false;
        }
    };

    void insertIntoTrie(Trie *root, string word)
    {
        Trie *ptr = root;
        for (int i = 0; i < word.size(); i++)
        {
            int indx = word[i] - 'a';
            if (ptr->children[indx] == nullptr)
            {
                ptr->children[indx] = new Trie();
            }

            ptr = ptr->children[indx];
        }
        ptr->isEndingNode = true;
    }

    vector<string> allMatch;
    void getAllMatch(Trie *node, string now)
    {
        if (node->isEndingNode)
        {
            allMatch.push_back(now);
        }

        for (int i=0; i<SZ; i++)
        {
            if (node->children[i] != nullptr)
            {
                char c = i + 'a';
                string temp = now + c;
                getAllMatch(node->children[i], temp);
            }
        }
    }

    vector<vector<string>> getAns(Trie *root, string searchWord)
    {
        vector<vector<string>> ans;
        Trie *ptr = root;
        for (int i = 0; i < searchWord.size(); i++)
        {
            int indx = searchWord[i] - 'a';
            allMatch.clear();
            if (ptr && ptr->children[indx] != nullptr)
            {
                ptr = ptr->children[indx];
                getAllMatch(ptr, "");
                for (int j = 0; j < allMatch.size(); j++)
                {
                    allMatch[j] = searchWord.substr(0, i+1) + allMatch[j];
                }
            }
            else
            {
                ptr = nullptr;
            }

            ans.push_back(allMatch);
        }
        return ans;
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)
    {
        Trie *root = new Trie();

        for (int i = 0; i < products.size(); i++)
        {
            insertIntoTrie(root, products[i]);
        }

        return getAns(root, searchWord);
    }
};


int main(){

    vector<string> products;
    products.push_back("mobile");
    products.push_back("mouse");
    products.push_back("moneypot");
    products.push_back("monitor");
    products.push_back("mousepad");

    string searchWord = "mouse";

    Solution sol;
    vector<vector<string>> ans = sol.suggestedProducts(products, searchWord);
    for (int i=0; i<ans.size(); i++)
    {
        cout << searchWord.substr(0, i+1) << ": " << endl;
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}