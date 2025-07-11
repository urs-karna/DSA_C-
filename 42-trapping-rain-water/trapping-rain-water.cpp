class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        // prefix height
        int leftmax = 0, rightmax = 0, totalWater = 0;
        int l = 0, r = n - 1;

        while (l < r) {
            if (arr[l] < arr[r]) {

                if (leftmax > arr[l]) {
                    totalWater += leftmax - arr[l];
                } else
                    leftmax = arr[l];

                l++;
            } else {

                if (rightmax > arr[r]) {
                    totalWater += rightmax - arr[r];
                }

                else {
                    rightmax = arr[r];
                }

                r--;
            }
        }

        return totalWater;
    }
};