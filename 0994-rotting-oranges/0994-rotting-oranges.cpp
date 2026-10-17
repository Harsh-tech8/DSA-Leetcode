class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<pair<int, int>, int>> q;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }
        
        int maxTime = 0;
        
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        
        while(!q.empty()) {
            auto current = q.front();
            q.pop();
            
            int r = current.first.first;
            int c = current.first.second;
            int t = current.second;
            
            maxTime = max(maxTime, t);
            
            for(int i = 0; i < 4; i++) {
                int nRow = r + dRow[i];
                int nCol = c + dCol[i];
                
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1) {
                    grid[nRow][nCol] = 2;
                    q.push({{nRow, nCol}, t + 1});
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    return -1; 
                }
            }
        }
        
        return maxTime;
    }
};