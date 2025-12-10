class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        pair<int,int>src = {0,0};
        int n = grid.size();
        int m = grid[0].size();
        pair<int,int> destination = {n-1, n-1};
         vector<vector<int>>dist(n,vector<int>(m,1e9) );
        dist[src.first][src.second] = 0;
        
        queue<pair<int,pair<int,int>>> q;
        if(grid[0][0] ==1 || grid[n-1][n-1]== 1) return -1;
      if(src.first == destination.first && src.second == destination.second) {
          return 1;
      }

        
        q.push({1,{src.first, src.second}} );
        
       int  drow[] = { -1, -1,0,1, 1, 1, 0,-1};
       int  dcol[] = {0, 1,1,1,0,-1,-1,-1};
        
        while(!q.empty()) {
            
            auto it = q.front();
            
            q.pop();
            
            int dis = it.first;
            
            int row = it.second.first;
            int col = it.second.second;
            
            for( int i =0; i< 8;i++) {
                
            int     nrow = row + drow[i];
             int    ncol = col + dcol[i];
                
                
                if( nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                   && grid[nrow][ncol]==0 && dis +1 < dist[nrow][ncol]    ) {
                       
                       
                       dist[nrow][ncol] = dis +1;
                       if(nrow == destination.first && ncol == destination.second ) 
                             return dis +1 ;
                       q.push({dis +1, { nrow,ncol}});
                   }
            }
        }
        
        return -1;
    }
};