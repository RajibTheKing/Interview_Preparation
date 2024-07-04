class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        // check columns
        for(int j = 0; j < n; j++)
        {
            set<char> st;
            for(int i = 0; i < n; i++)
            {
                char c = board[i][j];
                cout << c << endl;
                if (c != '.')
                {
                    if (st.find(c) == st.end())
                        st.insert(c);
                    else return false;
                }
            }
        }

        // check rows
        for(int i = 0; i < n; i++)
        {
            set<char> st;
            for(int j = 0; j < n; j++)    
            {
                char c = board[i][j];
                if (c != '.')
                {
                    if (st.find(c) == st.end())
                        st.insert(c);
                    else return false;
                }
            }
        }

        // check 3x3 sub boxes
        for(int i = 0; i < n; i+=3)
        {
            for(int j = 0; j < n; j+=3)
            {
                set<char> st;
                for(int k = i; k < (i+3); k++)
                {
                    for(int l = j; l < (j+3); l++)
                    {
                        char c = board[k][l];
                        if (c != '.')
                        {
                            if (st.find(c) == st.end())
                                st.insert(c);
                            else return false;
                        }

                    }
                }
            }
        }
        return true;

    }
};