class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> nodes(n, vector<int>{});
        vector<bool> seen(n, false);
        int count = 0;
        stack<int> st;
        
        for (auto& edge : edges) {
            nodes[edge[0]].push_back(edge[1]);
            nodes[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++) {
            if (seen[i]) continue;

            count++;
            st.push(i);

            while (!st.empty()) {
                int node = st.top();
                st.pop();
                seen[node] = true;
                
                for (auto& child : nodes[node]) {
                    if (!seen[child]) st.push(child);
                }
            }
        }

        return count;
    }
};
