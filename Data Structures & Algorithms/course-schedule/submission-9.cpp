class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& edge : prerequisites) adj[edge[1]].push_back(edge[0]);

        // 0 = Unvisited, 1 = Visiting (Grey), 2 = Visited (Black)
        vector<int> state(numCourses, 0); 

        for (int i = 0; i < numCourses; i++) {
            if (state[i] != 0) continue;

            stack<int> st;
            st.push(i);

            while (!st.empty()) {
                int curr = st.top();

                if (state[curr] == 0) {
                    state[curr] = 1; // Mark Visiting (Grey)
                    for (int neighbor : adj[curr]) {
                        if (state[neighbor] == 1) return false; // Cycle!
                        if (state[neighbor] == 0) st.push(neighbor);
                    }
                } else {
                    // If we see it again and it's already Grey (1), 
                    // it means we've finished all its children.
                    if (state[curr] == 1) state[curr] = 2; // Mark Done (Black)
                    st.pop();
                }
            }
        }
        return true;
    }
};