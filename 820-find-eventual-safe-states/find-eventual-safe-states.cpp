class Solution {
private:
    bool DFS(int node, vector<int>& vis, vector<int>& Pathvis,
             vector<int>& check, vector<vector<int>>& adj) {

        vis[node] = 1;
        Pathvis[node] = 1;

        for (auto it : adj[node]) {

            if (!vis[it]) {
               if( DFS(it, vis, Pathvis, check, adj) == true ) {
                  check[it]= 0;
                return true;
               }
            } else if (Pathvis[it] == 1) {
                 check[it] = 0;
                return true;
            }
        }


        check[node] = 1;
        Pathvis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V, 0);
        vector<int> Pathvis(V, 0);
        vector<int> check(V, 0);
        vector<int> safeN;

        for (int i = 0; i < V; i++) {

            if (!vis[i]) {

                DFS(i, vis, Pathvis, check, adj);
            }
        }
    for(int i =0;i<V;i++) {
        if(check[i]==1 ) safeN.push_back(i);
    }

        return safeN;
    }
};