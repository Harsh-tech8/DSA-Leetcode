class Solution {
public:
    bool isCycleDFS(int source, vector<bool>& visited, vector<bool>& recPath, vector<vector<int>>& edges) {
        visited[source] = true;
        recPath[source] = true; 
        
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][1];
            int v = edges[i][0]; 
            
            if (u == source) {
                if (!visited[v]) {
                    if (isCycleDFS(v, visited, recPath, edges)) {
                        return true; 
                    }
                } 
                else if (recPath[v]) {
                    return true; 
                }
            } 
        }
        
        recPath[source] = false; 
        return false; 
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<bool> visited(n, false);
        vector<bool> recPath(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (isCycleDFS(i, visited, recPath, prerequisites)) {
                    return false;
                }
            }
        }
        return true;
    }
};