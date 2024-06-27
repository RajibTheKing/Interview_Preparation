class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        priority_queue<int> pq;
        int n = matrix.size();

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(pq.size() < k)
                {
                    pq.push(matrix[i][j]);
                }
                else
                {
                    if(matrix[i][j] < pq.top())
                    {
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
                //cout<<matrix[i][j] << ", "<< pq.top() << ", " << pq.size() <<endl;
            }
        }
        return pq.top();
    }
};

// k = 8
// n = 3
// 8 / 3 = 2
