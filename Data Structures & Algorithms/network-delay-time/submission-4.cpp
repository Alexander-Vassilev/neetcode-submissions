class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> m(n + 1, vector<pair<int, int>>{});
        vector<int> minTimes(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        int ret = 0;

        for (auto& time : times) {
            m[time[0]].push_back({time[1], time[2]});
        }

        q.push({0, k});
        minTimes[k] = 0;

        while (!q.empty()) {
            auto el = q.top();
            int node = el.second;
            q.pop();
            int currDistance = minTimes[node];

            if (currDistance < el.first) continue;

            for (auto& child : m[node]) {
                int newDistance = currDistance + child.second;

                if (newDistance < minTimes[child.first]) {
                    minTimes[child.first] = newDistance;
                    q.push({newDistance, child.first});
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
