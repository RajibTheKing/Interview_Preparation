class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // matrix transpose
        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++)
                swap(matrix[i][j], matrix[j][i]);

        // reverse row wise
        for(int i=0; i<n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};
/*

0,0 --> 0,2 --> 2,2 --> 2,0
0,1 --> 1,2 --> 2,1 --> 1,0
0,2 --> 2,2 --> 2,0 --> 0,0

 0, 1, 2
0
1
2

length = 3

0,0 --> 0, 2 //length - row - 1
0,1 --> 1, 2
0,2 --> 2, 2

1,0 --> 0, 1
1,1 --> 1, 1
1,2 --> 2, 1

2,0 --> 0, 0
2,1 --> 1, 0
2,2 --> 2, 0




*/