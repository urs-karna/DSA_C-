class Solution {
public:
    bool canJump(vector<int>& arr) {
        int n= arr.size();
        int max_idx=0;

        for(int i=0;i<n;i++) {


            if( i > max_idx) return false;

            max_idx=max(max_idx, i+ arr[i]);
            if( max_idx >= n-1) return true;

        }
       
     return true;
    

    }
};

 