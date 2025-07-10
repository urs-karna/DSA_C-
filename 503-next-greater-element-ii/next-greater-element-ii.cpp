class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n=nums.size();
       vector<int>ans(n,-1);
       stack<int> st;
       for(int i=2*n;i>=0 ;i--) {

            int idx=i % n;

               while( !st.empty() && st.top() <= nums[idx]) {
                st.pop();
               }

            if(st.empty()) {
                ans[idx]=-1;
            }
            else {
                ans[idx]=st.top();
            }
            st.push(nums[idx]);
        
       }
       return ans; 


    }
};