class Solution {

private: 
 void DFS(int row, int col, vector<vector<char>>& board, vector<vector<int >> &vis,int drow[], int dcol[], int n, int m) {

    vis[row][col] = 1;
     
     for(int k=0;k<4;k++) {
        
        int nrow = row + drow[k];
        int ncol = col + dcol[k];
         
         if(nrow >=0 && nrow< n && ncol >= 0 && ncol<m && vis[nrow][ncol]  ==0 && board[nrow][ncol]=='O' ) {
            DFS(nrow, ncol, board, vis, drow,dcol,n, m);
         }

    
     }

 }
public:


    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m  = board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
         int drow[]= { -1, 0, 1, 0 };
          int dcol[] = { 0, 1, 0, -1};

        for(int i=0;i<n;i++) {
            for(int j =0 ;j <m;j++) {

                if( i == 0 || i==n-1 || j==0 || j == m-1) {
                    if(board[i][j] == 'O') {
                      DFS(i, j, board, vis, drow,dcol,n, m);  }
                }
            }
        }
          


         for(int i =0;i<n ;i++) {

            for (int j=0;j<m;j++) {
               
               if(vis[i][j] == 0  && board[i][j]=='O') {
                 board[i][j] = 'X';

               }
               
            

            }
         }


    }
};