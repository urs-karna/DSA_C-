class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {

        vector<int> inDegree(V, 0);
        vector<vector<int>> adj(V);
         queue<int> q;
        for (int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            adj[v].push_back(u);
            inDegree[u]++;
        }

        for(int i =0; i < V;i++ ) {
            if(inDegree[i]==0) {
                q.push(i);
            }
        }
        int cnt = 0 ;
       while(!q.empty())  {

        int node = q.front();
        cnt++;
         q.pop();
          
          for( auto it : adj[node] ) {

            inDegree[it]--;
            if( inDegree[it] == 0) q.push(it);
          }
       }

       if (cnt == V)  return true;
       return false ;
    }
};