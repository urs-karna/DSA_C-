class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> ans(n,-1);
        unordered_map<int,int>mp;
         for(int i=0;i<m;i++) mp[nums2[i]]=i;
       
        for(int i=0;i<n;i++) {
            int ele=nums1[i];
            
                    int idx=mp[ele]+1;
                    while(idx< m) {
                        if( nums2[idx] > ele) {
                            ans[i]=nums2[idx];
                            break;
                        }
                        idx++;      
            } 
        }
        return ans;

    }
};