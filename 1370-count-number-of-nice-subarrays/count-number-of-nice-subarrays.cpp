class Solution {
public:
    
    int count_arr(vector<int> & arr , int k)
    {
        if(k<0 ) return 0;
      int l=0,r=0, cnt=0,sum=0;
      int n=arr.size();
      while(r <n) {
         
         if( arr[r] % 2 !=0 ) sum++;
          
          while(sum > k) {
             if( arr[l] % 2 != 0) sum--;  
                l++;
          }

          cnt= cnt + (r-l+1);
          r++;
      }

    return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
       
       int x= count_arr(nums,k);
       int y=count_arr(nums,k-1);

       return x-y;

        
    }
};