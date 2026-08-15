class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> nodes(n, vector<int>{});
        vector<bool> visited(n, false);
        stack<pair<int, int>> st;
        
        for (auto& edge : edges) {
            nodes[edge[0]].push_back(edge[1]);
            nodes[edge[1]].push_back(edge[0]);
        }

        visited[0] = true;
        st.push({0, -1});
        int count = 0;

        while (!st.empty()) {
            pair<int, int> node = st.top();
            //cout << node.first << endl;
            st.pop();
            count++;

            for (auto& child : nodes[node.first]) {
                //cout << "child: " << child << endl;
                if (child != node.second) {
                    if (visited[child]) return false;

                    st.push({child, node.first});
                    //cout << "pushing child " << child << " with parent " << node.first << endl;
                    visited[child] = true;
                }
            }
        }

        //cout << "count: " << count << endl;

        bool retVal = count == n ? true : false;

        return retVal;
    }
};
