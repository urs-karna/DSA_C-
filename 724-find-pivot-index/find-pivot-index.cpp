class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        long long total_sum = accumulate(arr.begin(), arr.end(), 0);
        int n = arr.size();
        long long left_sum = 0;
        for (int i = 0; i < n; i++) {
            long long right_sum = total_sum - left_sum - arr[i];
            if (left_sum == right_sum) {
                return i;
            }
            left_sum += arr[i];
        }
        return -1;
    }
};