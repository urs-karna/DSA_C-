class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
          
        int V = numCourses;

        vector<vector<int>>adj(V);
        vector<int>inorder(V,0);
      
      for( int i =0; i<prerequisites.size();i++) {
      
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        adj[v].push_back(u);
        inorder[u]++;
      
      }

      queue<int>q;
      for(int i =0;i<V;i++) {

        if(inorder[i] == 0){
            q.push(i);
        }
      }

      int cnt =0;

      while(!q.empty()) {
        
        int node = q.front();
        q.pop();
        cnt++;
      for ( auto it : adj[node]){

        inorder[it]--;
        if(inorder[it]==0 ) q.push(it);
      }


      }

      return cnt== V;


    }
};