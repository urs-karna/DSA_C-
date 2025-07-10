class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans(n, -1);
        stack<int> st;
        unordered_map<int, int> mpp;
        for (int i = m - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
             if (!st.empty()) mpp[nums2[i]] = st.top();

            else {
                mpp[nums2[i]] = -1;
            }
            st.push(nums2[i]);
        }
        for (int i = 0; i < n; i++) {
            ans[i] = mpp[nums1[i]];
        }

        return ans;
    }
};