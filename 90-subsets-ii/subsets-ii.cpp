class Solution {
void find_subset( int idx, vector<int>& nums, vector<int>& sub, vector<vector<int>>& res) {


     res.push_back(sub);
   
   

   for( int i = idx ; i< nums.size();i++) {

     if( i > idx && nums[i] == nums[i -1]) {
        continue;
     }

     sub.push_back(nums[i]);
     find_subset(i+1, nums, sub, res);
     sub.pop_back();

   }
 }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         sort(nums.begin(), nums.end());  //
     vector<int>sub;
     vector<vector<int>>res;
     find_subset(0,nums,sub, res);
     return res;

    }
};