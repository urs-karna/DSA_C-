class Solution {
private: 
void DFS(int node , vector<int> & vis, vector<vector<int>>& isConnected ) {
   vis[node] = 1;
     
     for(int i =0 ; i<isConnected[0].size();i++) {

        if( isConnected[node][i] && !vis[i]) {

            DFS(i, vis, isConnected);
        }
     }



}
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
         
         int V= isConnected[0].size();
          vector<int>vis(V,0);
        int provinces = 0;

         for(int i=0;i<V;i++) {

            if( !vis[i]) {
                   provinces++;
                  DFS(i,vis,isConnected);

            }
         }

   return provinces;
    }
};