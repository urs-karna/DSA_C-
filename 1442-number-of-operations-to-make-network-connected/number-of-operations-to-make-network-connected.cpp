class DisjointSet {
public:
   
    vector<int> parent, size_arr;



DisjointSet( int n) {

    parent.resize(n);
    size_arr.resize(n);

    for(int i =0 ;i<n;i++) {

        parent[i] = i;
        size_arr[i] = 1;
    }
}

// for ultimate parent 
 int find_u_par( int node ) {
  
  if( node == parent[node]) return node;

  else {
    return parent[node] = find_u_par(parent[node]);
  }

 }

//union By size 

void UnionBysize( int u , int v) {

    int ulp_u = find_u_par(u);
    int ulp_v = find_u_par(v);

    if( ulp_u == ulp_v) return;

    if( size_arr[ulp_u] < size_arr[ulp_v]) {

        parent[ulp_u] = ulp_v;
        size_arr[ulp_v] += size_arr[ulp_u];
    }
    else {
        parent[ulp_v] = ulp_u;
        size_arr[ulp_u] += size_arr[ulp_v];
    }
}



};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int no_edges = connections.size();

        if(no_edges < n-1) return -1;
         int ExtraEdges = 0;
        DisjointSet ds(n);
        
        for( auto it : connections) {

            int u = it[0];
            int v = it[1];
            if( ds.find_u_par(u) == ds.find_u_par(v)) {
             
             ExtraEdges++;

            }
            else {
                ds.UnionBysize(u, v);
            }
        }

    int conC =0;
    for(int i=0;i<n;i++) {
        if(ds.parent[i] == i) conC++;
    }
    int ans = conC -1;
     if(ExtraEdges >= ans ) return ans;
     else  return -1;
    }
};