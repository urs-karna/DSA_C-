class Solution {
private: 
   void DFS(int row, int col, vector<vector<int>>&vis, vector<vector<int>>&grid, int &cnt, int drow[], int dcol[] ) {
        
        vis[row][col] = 1;
        cnt++;
        int n = grid.size();
        int m = grid[0].size();
        for(int i =0;i<4;i++) {
            
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if( nrow >= 0 && nrow<n && ncol >=0 && ncol <m && !vis[nrow][ncol] && grid[nrow][ncol]==1 ) {

                DFS(nrow,ncol, vis, grid, cnt , drow, dcol);
            }

        }

   }

public:
    int numEnclaves(vector<vector<int>>& grid) {
         int num = 0;
         int n = grid.size();
         int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
          int cnt = 0;
          int cnt1 = 0;
         int drow[] = { -1, 0, 1, 0 };
         int dcol[] = {  0, 1, 0, -1 };
     for(int i =0 ;i<n; i++) {

        for(int j=0 ; j<m;j++) {

           if (grid[i][j]==1 ) 
                      cnt1++;
        }
     }

          for(int i =0;i<n;i++) {

            for(int j = 0;j<m;j++) {
                if( i == 0 || i == n-1 || j == 0 || j == m-1) {
                    {
                           if(grid[i][j] == 1 ) {
                            DFS( i, j, vis, grid, cnt,drow,dcol);
                           }
                    }
                    
                    
                }
            }
          }
         

         for(int i =0 ;i< n;i++) {

            for(int j = 0; j< m; j++) {
                if( !vis[i][j]  && grid[i][j]== 1 ) {
                    num++;
                }
            }
         }
         return num;
        
    }
};