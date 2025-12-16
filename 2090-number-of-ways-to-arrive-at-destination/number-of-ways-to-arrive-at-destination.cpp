class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Create adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : roads) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        } 
        
        if(n == 1) return 1;
        
        // Change priority queue to use long long
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,0});
        
        // Change dist to long long
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        
        dist[0] = 0;
        ways[0] = 1;
        
        int mod = (int)1e9 + 7;
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            long long dis = it.first;  // This is now long long
            int node = it.second;
            
            // Skip outdated entries
            if(dis > dist[node]) continue;
            
            for(auto it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;
                
                long long newdist = dis + wt;  // Already long long
                
                if(newdist < dist[adjNode]) {
                    dist[adjNode] = newdist;
                    pq.push({newdist, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(newdist == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        
        if(dist[n-1] == LLONG_MAX) return 0;
        return ways[n-1] % mod;
    }
};