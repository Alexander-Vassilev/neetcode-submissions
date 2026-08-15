class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> nodes(numCourses);
        vector<bool> greySet(numCourses, false);
        vector<bool> blackSet(numCourses, false);
        vector<int> parentMap(numCourses, -1);
        vector<int> parentUnexploredChildren(numCourses, 0);
        stack<int> st;

        for (auto& edge : prerequisites) {
            nodes[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!blackSet[i]) {
                st.push(i);
                greySet[i] = true;
                int k = 0;

                while (!st.empty() && k < numCourses) {
                    int course = st.top();
                    int p = parentMap[course];
                    st.pop();
                    if (p >= 0) parentUnexploredChildren[p]--;
                    bool childAdded = false;

                    for (auto& c : nodes[course]) {
                        if (greySet[c]) return false;
                        if (!blackSet[c]) {
                            st.push(c);
                            parentMap[c] = course;
                            parentUnexploredChildren[course]++;
                            childAdded = true;
                            greySet[i] = true;
                        }
                    }

                    if (!childAdded) {
                        while (true) {
                            blackSet[course] = true;
                            greySet[course] = false;

                            if ((p >= 0) && (parentUnexploredChildren[p] == 0)) {
                                course = p;
                                p = parentMap[course];
                            } else {
                                break;
                            }
                        }
                    }

                    k++;
                }
            }
        }

        return true;
    }
};
