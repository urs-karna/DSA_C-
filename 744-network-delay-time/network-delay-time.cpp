class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        

        vector<vector<pair<int,int>>>adj(n+1);

        for(auto it : times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v,wt});

        }


        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k});

        vector<int>dist(n+1,1e9);
        dist[k] = 0;

        while(!q.empty()) {

            auto it = q.top();
            q.pop();

            int dis = it.first;
            int Node = it.second;

            for( auto it : adj[Node]) {
                 

                int adjNode = it.first;
                int wt  = it.second;

                if( dis + wt < dist[adjNode] ) {
                    dist[adjNode] = dis + wt;

                    q.push({dis + wt , adjNode});
                }
            }
        }
       int max_ele = INT_MIN;
        for(int i =1;i <= n ;i++) {
            if ( dist[i] == 1e9) return -1;
            max_ele = max(dist[i],max_ele);
        }
        return max_ele;
    }
};