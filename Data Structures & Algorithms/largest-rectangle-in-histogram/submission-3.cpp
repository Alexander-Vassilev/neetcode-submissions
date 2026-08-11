class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;
        stack<int> st;
        vector<vector<int>> boundaries(n, {0, n});

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                boundaries[st.top()][1] = i;
                st.pop();
            }

            st.push(i);
        }

        st = stack<int>();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                boundaries[st.top()][0] = i + 1;
                st.pop();
            }

            st.push(i);
        }

        //for (auto& b : boundaries) {
        //    std::cout << b[0] << ", " << b[1] << std::endl;
        //}

        for (int i = 0; i < n; i++) {
            int area = heights[i] * (boundaries[i][1] - boundaries[i][0]);
            res = max(res, area);
        }

        return res;
        /*
        int n = heights.size();
        int res = 0;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int top = st.top();
                int area = (i - top) * heights[top];
                res = max(area, res);
                st.pop();
            }

            st.push(i);
        }

        while (!st.empty()) {
            int top = st.top();
            int area = (n - top) * heights[top];
            res = max(area, res);
            st.pop();
        }

        return res;
        
        for (int i = 0; i < n; i++) {
            int rectStart = 0;
            int height = heights[i];
            int area = 0;
            //std::cout << "starting index: " << i << std::endl;

            for (int j = i + 1; j < n; j++) {
                if (heights[j] <= height) {
                    int width = j - i;
                    area = max(width * height, area);
                    //std::cout << "updated area: " << area << std::endl;
                    height = heights[j];
                    rectStart = j;
                }
            }
            
            area = max(area, (n - i) * height);
            //std::cout << "final area on this iteration: " << area << std::endl;

            res = max(res, area);
            //std::cout << std::endl;
        }

        return res;*/
    }
};
