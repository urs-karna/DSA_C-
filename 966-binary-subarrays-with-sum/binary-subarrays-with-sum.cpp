class Solution {
public:
    int find_sub_arr(vector<int> arr, int k) {
        if(k < 0) return 0;
        int n= arr.size();
        int sum = 0;
        int cnt = 0;
        int l = 0, r = 0;

        while (r < n) {

            sum += arr[r];

            while (sum > k) {

                sum -= arr[l];
                l++;
            }
            //find the all subarrays 

            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int n = nums.size();

        int x= find_sub_arr(nums, goal);
        int y= find_sub_arr(nums, goal-1);
        
        return x-y;


    }
};