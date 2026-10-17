class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        vector <vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>> q;

        for (int i = 0; i <n ; i++){
            for(int j = 0; j < m ; j++){
                if (grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = true;
                }
            }
        }
        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        while(q.size() > 0){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();

            ans = max(ans,time);

            for (int k = 0; k < 4; k++) {
                int nrow = i + drow[k];
                int ncol = j + dcol[k];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = true;
                    q.push({{nrow, ncol}, time + 1});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    return -1;
                }
            }
        }
        return ans;
    }
};