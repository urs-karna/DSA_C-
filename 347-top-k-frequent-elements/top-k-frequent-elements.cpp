class Solution {
public:
typedef pair<int,int>ppi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
      vector<int> res;
       unordered_map<int,int> mp;
     priority_queue<ppi,vector<ppi>,greater<ppi>>minH;
       for( int i =0 ;i<nums.size();i++) {

        mp[nums[i]]++;

       } 
      for( auto it : mp) {

        minH.push({it.second, it.first});
        if(minH.size() > k) minH.pop();
      }

       while( !minH.empty()) {
        res.push_back(minH.top().second);
        minH.pop();
       }
    return res;

    }
};