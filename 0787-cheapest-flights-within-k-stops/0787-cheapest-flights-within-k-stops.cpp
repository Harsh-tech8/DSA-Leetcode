class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for (auto& flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];
            adj[u].push_back({v, w});
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({src, {0, -1}});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int u = it.first;
            int cost = it.second.first;
            int stops = it.second.second;

            if (stops > k) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int edW = edge.second;

                if (cost + edW < dist[v] && stops + 1 <= k) {
                    dist[v] = cost + edW;
                    q.push({v, {dist[v], stops + 1}});
                }
            }
        }

        if (dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};