class Solution {
public:

   typedef pair<int,pair<int,int>>ppi;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

    vector<vector<int>> res;
    
    priority_queue<ppi>maxH;

    
     for(int i=0;i<points.size();i++) {
       int x = points[i][0];
       int y= points[i][1];

       int dist= ((x*x) + (y*y));

       maxH.push({dist,{x,y}});
       if(maxH.size() > k ) maxH.pop();
        
       
     }

     while( !maxH.empty() ) {
    vector<int>v= {maxH.top().second.first , maxH.top().second.second};
        res.push_back(v);
        maxH.pop();
     }

      return res;  
    }
};