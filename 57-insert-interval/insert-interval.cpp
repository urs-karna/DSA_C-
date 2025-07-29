class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      vector<vector<int>>copyIntervals(intervals.begin(),intervals.end()); 
     
    

        copyIntervals.push_back(newInterval);
    
    sort(copyIntervals.begin(),copyIntervals.end());
   
    vector<vector<int>>v;

    for(int i=0;i<copyIntervals.size();i++)  {

         if( v.size()==0 || copyIntervals[i][0] > v.back()[1] ){


            v.push_back(copyIntervals[i]);
         }
         else {

            v.back()[1]= max(v.back()[1], copyIntervals[i][1]);
         }

    }
    return v;

    }
};