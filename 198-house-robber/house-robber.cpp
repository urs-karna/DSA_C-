class Solution {

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev2 =0;
        int  prev= nums[0];

        for(int i = 1;i<n;i++) {

           int pick = nums[i];
           if( i > 1) {
            pick += prev2;
           } 
          int  notPick = prev;

           int curI = max(pick , notPick);

           prev2 = prev;
           prev = curI;

        } 

        return  prev;

    }
};