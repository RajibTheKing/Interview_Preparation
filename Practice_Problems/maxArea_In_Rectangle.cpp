class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxRectangle = 0;
        for(int i = matrix.size()-1; i>=0; i--)
        {
            //levelwise histogram making
            vector<int> heights(matrix[i].size(), 0);

            for(int j = 0; j<matrix[i].size(); j++)
            {
                for(int up = i; up>=0; up--)
                {
                    if(matrix[up][j] == '0')
                    {
                        break;
                    }
                    else
                    {
                        heights[j]++;
                    }
                }
                int area = largestRectangleArea(heights);
                maxRectangle = max(area, maxRectangle);
            }

        }
        return maxRectangle;
    }

    int largestRectangleArea(vector<int>& heights)
    {
        stack<int> st;
        int i = 0;
        int area = 0;
        int maxArea = -1;

        for (; i < heights.size(); i++)
        {
            // cout << "Pos : " << i << ", height[i] = " << heights[i] << endl;
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                if (heights[i] >= heights[st.top()])
                {
                    st.push(i);
                }
                else
                {
                    while(!st.empty() && heights[st.top()] > heights[i])
                    {
                        int top = st.top();
                        st.pop();

                        // if(st.empty())
                        //     cout << "      --> i = " << i << ", top = " << top << ", st.top() = empty" << endl;
                        // else
                        //     cout << "      --> i = " << i << ", top = " << top << ", st.top() = " << st.top() << endl;

                        if (st.empty())
                            area = heights[top] * i;
                        else
                            area = heights[top] * (i - st.top() - 1);

                        maxArea = max(maxArea, area);
                    }
                    st.push(i);
                }
            }
        }

        while(!st.empty())
        {
            int top = st.top();
            st.pop();

            if (st.empty())
                area = heights[top] * i;
            else
                area = heights[top] * (i - st.top() - 1);

            maxArea = max(maxArea, area);
        }

        return maxArea;

    }

};