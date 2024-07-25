class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int numberOfPeople = mat.size();
        for (int i = 0; i < numberOfPeople; i++)
        {
            bool flag;
            // first condition
            flag = true;
            for (int j = 0; j < numberOfPeople; j++)
            {
                if (mat[i][j] != 0)
                {
                    flag = false;
                    break;
                }
            }

            if (!flag) continue;

            // second condition
            flag = true;
            for (int j = 0; j < numberOfPeople; j++)
            {
                if (j == i) continue;
                if (mat[j][i] != 1)
                {
                    flag = false;
                    break;
                }
            }
            if (!flag) continue;
            return i;
        }
        return -1;
    }
};