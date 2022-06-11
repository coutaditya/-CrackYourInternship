int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

class Solution {
public:
    void dfs(vector<vector<int> > &image, int i, int j, int curColor ,int newColor){
        if(image[i][j]==newColor) return; 
        
        image[i][j] = newColor;
        
        int n = image.size();
        int m = image[0].size();
        
        for(int k=0; k<4; k++){
            int xx = i + dx[k];
            int yy = j + dy[k];
            
            if(xx<n && xx>=0 && yy<m && yy>=0 && (image[xx][yy]==curColor)){
                dfs(image, xx, yy, curColor, newColor);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        
        dfs(image, sr, sc, image[sr][sc], newColor);
        
        return image;
    }
};