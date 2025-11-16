class Solution {

private:

    bool DFS(int node, int col, vector<int>&color_arr, vector<vector<int>> graph) {

        color_arr[node] = col;

        for(auto it : graph[node]) {

            if(color_arr[it] == -1) {
                
                if(DFS(it, !col, color_arr, graph) == false) return false;

            }
            else if (color_arr[it] == col) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {

       int V = graph.size();
       
       //instead of visted array take a color array which markes as -1 that is no color indication 

       vector<int>color_arr(V,-1);

       // imagine there are two colors they are 0,1 

       for(int i =0 ;i<V;i++) {

        if( color_arr[i] == -1) {

             if ( DFS(i, 0, color_arr, graph) == false ) {
                return false;
             }
        }

       }
    return true;
    }
};