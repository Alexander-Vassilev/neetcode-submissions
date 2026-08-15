class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res{};
        vector<vector<int>> nodes(numCourses, vector<int>{});
        // 0 = unvisited, 1 = visiting, 2 = no cycle, 3 = unconnected
        vector<uint8_t> states(numCourses, 3);
        vector<int> indegrees(numCourses, 0);
        res.reserve(numCourses);
        stack<int> st;

        for (auto& prereq : prerequisites) {
            states[prereq[0]] = 0;
            states[prereq[1]] = 0;
            nodes[prereq[1]].push_back(prereq[0]);
            indegrees[prereq[0]]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] > 0) continue;
            if (states[i] == 3) {
                res.push_back(i);
                continue;
            }

            st.push(i);

            while (!st.empty()) {
                int course = st.top();
                //cout << "stack size: " << st.size() << ", course: " << course << endl;

                if (states[course] == 0) {
                    states[course] = 1;

                    for (auto& node : nodes[course]) {
                        if (states[node] == 1) {
                            return {};
                        } else if (states[node] == 0) {
                            st.push(node);
                        } else {
                            states[course] = 2;
                        }

                    }
                } else {
                    states[course] = 2;
                    res.push_back(course);
                    st.pop();
                }
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
