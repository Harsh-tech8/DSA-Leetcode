class Solution {
private:
    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid, int n, int m) {
        // Base case: check out of bounds, already visited, or water ('0')
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] != '1') {
            return;
        }
        
        // Mark the current cell as visited
        visited[i][j] = true;
        
        // Recursively visit all 4 neighboring directions (Top, Right, Bottom, Left)
        dfs(i - 1, j, visited, grid, n, m); // Top
        dfs(i, j + 1, visited, grid, n, m); // Right
        dfs(i + 1, j, visited, grid, n, m); // Bottom
        dfs(i, j - 1, visited, grid, n, m); // Left
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int islandsCount = 0;
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        
        // Initialize visited matrix with false
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        // Iterate through each cell in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If we find unvisited land, it forms a new island
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(i, j, visited, grid, n, m);
                    islandsCount++;
                }
            }
        }
        
        return islandsCount;
    }
};