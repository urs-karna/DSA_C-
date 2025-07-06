class Solution {
public:
     
     void FindCombo(int idx,int target,vector<int>nums,vector<vector<int>> & ans,vector<int>SubSet){
            

            if(target==0) {
              ans.push_back(SubSet);
              return;
            }
            for(int i=idx;i<nums.size();i++) {
                if( i > idx && nums[i]==nums[i-1]) continue;

                if( nums[i] > target) break;
               SubSet.push_back(nums[i]);
               FindCombo(i+1,target - nums[i], nums,ans,SubSet);
               SubSet.pop_back();


            }



     }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>SubSet;
         FindCombo(0,target,candidates,ans,SubSet);
        
        return ans;
        
    }
};