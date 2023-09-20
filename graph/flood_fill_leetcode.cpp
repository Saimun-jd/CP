class Solution {
private:
  void dfs(int i, int j, int initColor, int newColor, vector<vector<int>>& image) {
    int n = image.size();
    int m = image[0].size();
    if(i<0 || j<0 || i>=n || j>=m) return;
    if(image[i][j] != initColor) return;

    image[i][j] = newColor;

    dfs(i+1, j, initColor, newColor, image);
    dfs(i-1, j, initColor, newColor, image);
    dfs(i, j+1, initColor, newColor, image);
    dfs(i, j-1, initColor, newColor, image);
  }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
        int initColor = image[sr][sc];
        if(initColor != color) {
          dfs(sr, sc, initColor, color, image);
        }
        return image;
    }
};