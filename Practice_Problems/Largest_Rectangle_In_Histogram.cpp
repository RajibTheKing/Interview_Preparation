//explanation: https://www.youtube.com/watch?v=ZmnqCZp9bBs


class Solution {
public:
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

// i = 6, top = 1
// area = 1 * 2 = 4

//        6 

