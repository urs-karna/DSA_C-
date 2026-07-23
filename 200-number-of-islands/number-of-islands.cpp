class Solution {

private:
      void DFS(int &row, int &col,vector<vector<char>>& grid,vector<vector<int>>& vis,int drow[], int dcol[]) {
      
      int n = grid.size();
       int m = grid[0].size();


        vis[row][col] = 1;

        for( int i=0;i<4;i++) {
           int  nrow = row + drow[i];
           int  ncol = col +dcol[i];


        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol< m && grid[nrow][ncol]== '1' && !vis[nrow][ncol]){

            DFS(nrow,ncol,grid,vis,drow,dcol);
        }
        }

      }

public:
    int numIslands(vector<vector<char>>& grid) {
        
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0));
       int cnt=0;
       int drow[] = {-1,0,1,0};
       int dcol[] = {0,1,0,-1};
        for(int i=0; i<n;i++) {

            for(int j =0 ;j<m;j++) {

                if(!vis[i][j] && grid[i][j]== '1') {
                    cnt++;
                    DFS(i,j,grid,vis,drow,dcol);
                }


            }
        }

        return cnt;
    }
};