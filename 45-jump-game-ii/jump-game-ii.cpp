class Solution {
private:
  int minJumps(int idx,vector<int>& nums,vector<int>& dp) {

   if ( idx >= nums.size()-1 ) return 0;
   if(dp[idx] != -1) return dp[idx];

   int mini = INT_MAX;

   for(int i = 1; i <= nums[idx]; i++){

    int jumps =  minJumps(idx + i, nums, dp);
 
     if (jumps != INT_MAX) {
        mini = min(mini, 1 + jumps);
      }
    }

   
   return   dp[idx] = mini;


  }

public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return minJumps(0,nums,dp);

        
    }
   



};