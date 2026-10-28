class Solution {
public:
    void dfs(int u, int parent, int &time, vector<int>& disc, vector<int>& low, vector<vector<int>>& adj, vector<vector<int>>& criticalConnections) {
        disc[u] = low[u] = ++time;
        
        for (int v : adj[u]) {
            if (v == parent) continue;
            
            if (disc[v] != -1) {
                low[u] = min(low[u], disc[v]);
            } else {
                dfs(v, u, time, disc, low, adj, criticalConnections);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    criticalConnections.push_back({u, v});
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto& conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }
        
        int time = 0;
        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        vector<vector<int>> criticalConnections;
        
        for (int i = 0; i < n; i++) {
            if (disc[i] == -1) {
                dfs(i, -1, time, disc, low, adj, criticalConnections);
            }
        }
        
        return criticalConnections;
    }
};