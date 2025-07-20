class Solution {
public:
     int  cnt_sub(vector<int> & nums , int k) {
        int cnt=0;
        int n=nums.size();
         unordered_map<int ,int>mpp;
         int l=0,r=0;
         while(r< n) {
            mpp[nums[r]]++;

            while(mpp.size() > k) {
              mpp[nums[l]]--;
              if( mpp[nums[l]]==0)  {
                mpp.erase( nums[l]);
              }
              l++;
              
            }
            if( mpp.size() <= k) {
                cnt += r-l+1;
            }
       r++;

         }
      return cnt;
     }



    int subarraysWithKDistinct(vector<int>& nums, int k) {
       
         int x= cnt_sub(nums, k);
         int y= cnt_sub(nums,k-1);
        return x-y;
    }
};