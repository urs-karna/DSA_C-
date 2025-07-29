class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newIntervals) {
      vector<vector<int>>copyIntervals(intervals.begin(),intervals.end());  
   
    vector<vector<int>>res;
    int i=0;
    int n=copyIntervals.size();
  //left
    while(i < n && copyIntervals[i][1] < newIntervals[0])   {
          res.push_back(copyIntervals[i]);
          i++;
    }
    //find overlapping 

    while( i < n && copyIntervals[i][0] <= newIntervals[1]) {

        newIntervals[0] = min (newIntervals[0], copyIntervals[i][0]);
        newIntervals[1]  = max( newIntervals[1], copyIntervals[i][1]);
        i++;
    }
    res.push_back(newIntervals);

    while(i< n) {
     res.push_back(copyIntervals[i]);
     i++;


    }

    return res;

    }
};