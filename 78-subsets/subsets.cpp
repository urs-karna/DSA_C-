class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n= nums.size();
       vector<vector<int>>res;

       for(int i=0;i<(1<<n);i++) {
          vector<int>sub;
          for(int j=0;j<n;j++) {
            if( i & (1<<j) ) sub.push_back(nums[j]);
          }
          res.push_back(sub);
       }
       return res;
    }
};