class Solution {
public:

    void FindCombinations(int i, int target,vector<int>Candidates,vector<vector<int>>&ans,vector<int>SubSet)  {

        if(i== Candidates.size()) {
            if(target==0) {
                ans.push_back(SubSet);
                return;
            }
            return;  
        }
    
       if(Candidates[i] <= target) {

        SubSet.push_back(Candidates[i]);
        FindCombinations(i, target- Candidates[i],Candidates,ans,SubSet);
        SubSet.pop_back();
       }


      FindCombinations(i+1, target,Candidates,ans,SubSet);


    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>>ans;
      vector<int>SubSet;
      FindCombinations(0,target, candidates,ans,SubSet);
      return ans;  
  
    }
};