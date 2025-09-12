class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        

        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> vis(image.begin(),image.end());

        queue<pair<int,int>>q;
         int same_col = image[sr][sc];
        q.push({sr,sc});
        vis[sr][sc] = color;
        
         int drow[] = {-1, 0, 1, 0 };
         int dcol[] = {0, 1, 0, -1  };

        while(!q.empty()) {
             
             int row = q.front().first;
             int col = q.front().second;
             q.pop();

             for(int i =0 ; i<4;i++) {

                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if( nrow >= 0 && nrow< n && ncol>=0 && ncol<m && image[nrow][ncol]==same_col && vis[nrow][ncol] != color) {
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = color;
                }
             }

        }
        return vis;
    }
};