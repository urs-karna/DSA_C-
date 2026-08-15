class Disjoint {

public:
  vector<int>sizeArr, parent;
  //contrctor 
   Disjoint(int n) {

     sizeArr.resize(n+1,1);
     parent.resize(n+1);
     
     for(int i = 0 ; i<= n;i++){
        parent[i] = i;
     }
   }

   int FindUpar(int node){
        
        if( parent[node] == node) return node;

        return  parent[node]= FindUpar(parent[node]);

   }

   void UnionBySize(int ulp_u, int ulp_v) {


       if( ulp_u == ulp_v) return;

       if( sizeArr[ulp_u] < sizeArr[ulp_v]) {

            parent[ulp_u] = ulp_v;
            sizeArr[ulp_v] += sizeArr[ulp_u];
       }
       else {
            parent[ulp_v] = ulp_u;
            sizeArr[ulp_u] += sizeArr[ulp_v];

       }

   }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
    int cnt=0, ExtraCnt =0;

    Disjoint  ds(n);

    for( int  i =0; i< connections.size();i++) {

        int u = connections[i][0];
        int v = connections[i][1];
        int utp_u = ds.FindUpar(u);
        int utp_v = ds.FindUpar(v);

        if( utp_u == utp_v) ExtraCnt++;
        else {
            cnt++;
            ds.UnionBySize(utp_u, utp_v);
        }

        
    }

    if (cnt+ ExtraCnt >= n-1) return n-1-cnt;
    else return -1;

    }
};