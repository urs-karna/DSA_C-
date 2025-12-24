class DisJointSet {

   public:

      vector<int>parent,size;

      DisJointSet(int n) {

        parent.resize(n+1);
        size.resize(n+1);

        for(int i =0 ;i<=n;i++) {

            parent[i] =i;
            size[i] = 1;

        }
      }

      int find_uPar(int node) {

        if(node== parent[node]) return node;

        else {
            return parent[node] = find_uPar(parent[node]);
        }
      }

      void UnionBySize(int u, int v) {

        int ulp_u = find_uPar(u);
        int ulp_v = find_uPar(v);
        if(ulp_u == ulp_v) return;

        if( size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = parent[ulp_v];
            size[ulp_v] += size[ulp_u];
            
        }
        else {
             parent[ulp_v] = parent[ulp_u];
             size[ulp_u] += size[ulp_v];
        }
      }


};

class Solution {

public:
    int removeStones(vector<vector<int>>& stones) {
        int  n = stones.size();
        int maxRow = 0;
        int maxCol = 0;

        for( auto it : stones) {
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }

        DisJointSet  ds(maxRow + maxCol+1);
         unordered_map<int,int>mapStones;

        for( auto it : stones) {
             
             int rowStone = it[0];
             int colStone  = it[1] + maxRow + 1;

             ds.UnionBySize(rowStone, colStone);
             mapStones[rowStone] = 1;
             mapStones[colStone] = 1;
    
        }
        int cnt = 0;
        for( auto it : mapStones) {
          
          if(ds.find_uPar(it.first) == it.first)  cnt++;
                
            
        }
        return n - cnt;
          
    }
};