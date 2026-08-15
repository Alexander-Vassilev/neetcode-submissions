class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& edge : prerequisites) {
            // Standard: prerequisites[1] is the prereq for prerequisites[0]
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> state(numCourses, 0); // 0: Unvisited, 1: Visiting, 2: Visited
        vector<int> result;
        result.reserve(numCourses);

        for (int i = 0; i < numCourses; i++) {
            if (state[i] != 0) continue;

            stack<int> st;
            st.push(i);

            while (!st.empty()) {
                int curr = st.top();

                if (state[curr] == 0) {
                    state[curr] = 1; // Mark Grey (Visiting)
                    for (int neighbor : adj[curr]) {
                        if (state[neighbor] == 1) return {}; // Cycle detected!
                        if (state[neighbor] == 0) st.push(neighbor);
                    }
                } else {
                    if (state[curr] == 1) {
                        state[curr] = 2; // Mark Black (Done)
                        result.push_back(curr); // ADD TO RESULT HERE
                    }
                    st.pop();
                }
            }
        }

        // The nodes were added in "Finish Order", so we reverse for "Start Order"
        reverse(result.begin(), result.end());
        return result;
    }
};