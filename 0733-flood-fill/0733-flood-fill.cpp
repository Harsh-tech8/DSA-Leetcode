class Solution {
public:
    void dfs(vector<vector<int>>& image,int i, int j , int newcol , int orcol){
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] == newcol || image[i][j] != orcol){
            return;
        }
        image[i][j] = newcol;

        dfs(image,i-1,j,newcol,orcol);
        dfs(image,i,j+1,newcol,orcol);
        dfs(image,i+1,j,newcol,orcol);
        dfs(image,i,j-1,newcol,orcol);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,color,image[sr][sc]);

        return image;
    }
};