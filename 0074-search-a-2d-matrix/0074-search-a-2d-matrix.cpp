class Solution {
public:
    bool searchrow(vector<vector<int>>& mat, int tar, int row) {
        int n = mat[0].size();
        int st = 0, end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (tar == mat[row][mid]) {
                return true;
            } else if (tar > mat[row][mid]) {
                st = mid + 1; // Fixed: search right half
            } else {
                end = mid - 1; // Fixed: search left half
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int m = mat.size(), n = mat[0].size();
        int strow = 0, endrow = m - 1;
        
        while (strow <= endrow) {
            int midrow = strow + (endrow - strow) / 2;
            
            if (tar >= mat[midrow][0] && tar <= mat[midrow][n - 1]) {
                return searchrow(mat, tar, midrow); // Added return statement
            } else if (tar > mat[midrow][n - 1]) {
                strow = midrow + 1; // Fixed: move down
            } else {
                endrow = midrow - 1; // Fixed: move up
            }
        }
        return false;
    }
};