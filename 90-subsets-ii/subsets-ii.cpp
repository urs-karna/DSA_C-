class Solution {
public:
    void AddSubSets(vector<int> nums, vector<vector<int>>& ans,
                    vector<int> SubSet, int i) {

        if (i == nums.size()) {
            ans.push_back(SubSet);
            return;
        }
        SubSet.push_back(nums[i]);

        AddSubSets(nums, ans, SubSet, i + 1);
        SubSet.pop_back();
        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[idx - 1]) {
            idx++;
        }
        AddSubSets(nums, ans, SubSet, idx);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> SubSet;
        AddSubSets(nums, ans, SubSet, 0);
        return ans;
    }
};