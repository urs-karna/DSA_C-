class Solution {
public:
void  AddSubSets(vector<int> nums, vector<vector<int>>&ans, vector<int> SubSet, int i) {
        
        if(i==nums.size()) {
            ans.push_back(SubSet);
            return;
        }
        //include
        SubSet.push_back(nums[i]);
        AddSubSets(nums, ans, SubSet,i+1);
        
        SubSet.pop_back();
        AddSubSets(nums,ans,SubSet,i+1);
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>SubSet;
        
        AddSubSets(nums, ans ,SubSet,0);
        return ans;
    }
};