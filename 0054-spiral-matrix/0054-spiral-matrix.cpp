class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int srow = 0, erow = m - 1, scol = 0, ecol = n - 1;
        vector<int> ans;

        while (srow <= erow && scol <= ecol) {
            for (int i = scol; i <= ecol; i++) {
                ans.push_back(mat[srow][i]);
            }
            srow++;

            for (int j = srow; j <= erow; j++) {
                ans.push_back(mat[j][ecol]);
            }
            ecol--;

            if (srow <= erow) {
                for (int i = ecol; i >= scol; i--) {
                    ans.push_back(mat[erow][i]);
                }
                erow--;
            }

            if (scol <= ecol) {
                for (int j = erow; j >= srow; j--) {
                    ans.push_back(mat[j][scol]);
                }
                scol++;
            }
        }
        return ans;
    }
};