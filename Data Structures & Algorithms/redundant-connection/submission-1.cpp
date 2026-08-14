class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> groups(edges.size() + 1, -1);

        for (auto& edge : edges) {
            int group1 = groups[edge[0]];
            int group2 = groups[edge[1]];

            if (group1 == -1 && group2 == -1) {
                int smallerNode = min(edge[0], edge[1]);
                groups[edge[0]] = smallerNode;
                groups[edge[1]] = smallerNode;
            } else if (group1 == -1) {
                groups[edge[0]] = group2;
            } else if (group2 == -1) {
                groups[edge[1]] = group1;
            } else {
                if (group1 == group2) {
                    return edge;
                } else {
                    int oldGroup = group2;
                    int newGroup = group1;

                    if (group1 < group2) {
                        groups[edge[1]] = group1;
                    } else {
                        groups[edge[0]] = group2;
                        oldGroup = group1;
                        newGroup = group2;
                    }

                    for (auto& group : groups) {
                        if (group == oldGroup) {
                            group = newGroup;
                        }
                    }
                }
            }
        }

        /*
        vector<vector<int>> nodeConnections(edges.size() + 1);
        queue<vector<int>> q;
        vector<bool> seen(edges.size(), false);
        set<vector<int>> removableEdges;
        seen.reserve(edges.size());

        for (auto& edge : edges) {
            nodeConnections[edge[0]].push_back(edge[1]);
            nodeConnections[edge[1]].push_back(edge[0]);
        }

        for (auto& node : nodeConnections[1]) {
            q.push({1, node});
            seen[node] = true;
        }

        while (!q.empty()) {
            vector<int> edge = q.front();
            q.pop();

            if (seen[edge[1]]) {
                sort(edge.begin(), edge.end());
                removableEdges.insert(edge);
            }

            for (auto& node : nodeConnections[edge[1]]) {
                if (node == edge[0]) continue;

                vector<int> newEdge = {edge[1], node};

                if (seen[node]) {
                    removableEdges.insert(newEdge);
                } else {
                    q.push({1, node});
                    seen[node] = true;
                }
            }
        }

        for (int i = edges.size() - 1; i >= 0; i--) {
            if (removableEdges.contains(edges[i])) {
                return edges[i];
            }
        }
        */
    }
};
