#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 1. Adjacency List: Use a flat vector of vectors for the graph
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        // 2. minTimes initialized to 'Infinity'
        vector<int> minTimes(n + 1, 1e9); // Using 1e9 is safer/cleaner than INT_MAX
        minTimes[k] = 0;

        // 3. MIN-Priority Queue: stores {time, node}
        // std::greater makes it a min-heap instead of a max-heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [time, u] = pq.top();
            pq.pop();

            // Optimization: If we found a better path already, ignore this one
            if (time > minTimes[u]) continue;

            for (auto& [v, weight] : adj[u]) {
                if (minTimes[u] + weight < minTimes[v]) {
                    minTimes[v] = minTimes[u] + weight;
                    pq.push({minTimes[v], v});
                }
            }
        }

        // 4. Result calculation using STL algorithms
        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (minTimes[i] == 1e9) return -1;
            maxTime = max(maxTime, minTimes[i]);
        }

        return maxTime;
    }
};