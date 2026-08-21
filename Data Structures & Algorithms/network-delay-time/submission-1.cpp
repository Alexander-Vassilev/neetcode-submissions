class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> m(n + 1, vector<pair<int, int>>{});
        vector<int> minTimes(n + 1, INT_MAX);
        queue<int> q;
        int ret = 0;

        for (auto& time : times) {
            m[time[0]].push_back({time[1], time[2]});
        }

        q.push(k);
        minTimes[k] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            int currDistance = minTimes[node];

            for (auto& child : m[node]) {
                int newDistance = currDistance + child.second;

                if (newDistance < minTimes[child.first]) {
                    minTimes[child.first] = newDistance;
                    q.push(child.first);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (minTimes[i] == INT_MAX) return -1;

            ret = max(ret, minTimes[i]);
        }

        return ret;
    }
};
