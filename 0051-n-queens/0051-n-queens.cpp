class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // 1. Check vertically up
        for(int i=0; i<row; i++) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }
        
        // 2. Check left diagonal up
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        
        // 3. Check right diagonal up
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        
        return true;
    }

    void nQueens(vector<string>& board, int row, int n, vector<vector<string>>& ans) {
        // Base case: Agar saari rows complete ho gayi
        if(row == n) {
            ans.push_back(board);
            return;
        }

        // Ek row ke har column par Queen rakh kar check karna
        for(int col=0; col<n; col++) {
            if(isSafe(board, row, col, n)) {
                board[row][col] = 'Q';         // Queen place ki
                nQueens(board, row+1, n, ans); // Next row ke liye recursive call
                board[row][col] = '.';         // Backtracking step (Undo the choice)
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        // Board ko '.' (empty) se initialize kiya
        vector<string> board(n, string(n, '.')); 
        
        nQueens(board, 0, n, ans);
        return ans;
    }
};