class Solution {
public:

void DFS(int node , vector<int> &vis, vector<vector<int>>adj , vector<vector<int>>mat ) {

    vis[node] = 1;

    for( auto i : adj[node]) {
        if( !vis[i]) {
            DFS(i ,vis, adj, mat );
        }
    }
}

    int findCircleNum(vector<vector<int>>& mat ) {
        
        int V = mat[0].size();
       vector<vector<int>>adj(V);
       vector<int>vis(V,0);
       int provinces = 0;
      // adj list 
       for(int i =0 ;i<V;i++) {

         for(int j=0;j<V;j++) {
             if(mat[i][j] == 1 && i != j) {
                adj[i].push_back(j);
                adj[j].push_back(i);
             } 
         }
       }
   
     for(int i=0;i<V;i++) {

        if( !vis[i]) {
           provinces ++;

           DFS(i, vis, adj, mat);

        }
     }
 return provinces;
    }
};