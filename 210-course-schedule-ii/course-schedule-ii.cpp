class Solution {
private:
    bool DFS(int node, vector<vector<int>> adj, vector<int>& vis,
             vector<int>& PathVis, vector<int>& res) {

        vis[node] = 1;

        PathVis[node] = 1;

        for (auto it : adj[node]) {

            if (!vis[it]) {

                if (DFS(it, adj, vis, PathVis, res) == true)
                    return true;
            } else if (PathVis[it] == 1)
                return true;
        }

        PathVis[node] = 0;
        res.push_back(node);
        return false;
    }

public:
    vector<int> findOrder(int V, vector<vector<int>>& grid) {
        // adj list
        vector<vector<int>> adj(V);
        for (int i = 0; i < grid.size(); i++) {
            int u = grid[i][0];
            int v = grid[i][1];
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0);
        vector<int> PathVis(V, 0);
        vector<int> res;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (DFS(i, adj, vis, PathVis, res) == true)
                    return {};
            }
        }

      reverse(res.begin(),res.end());
      
        return res;
    }
};