class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        if (k > n)
            return 0;
        int max_sum = 0, sum = 0;

        int r = n - 1;
        for (int l = 0; l < k; l++) {

            sum += arr[l];
        }
        if (k == n)
            return sum;
        max_sum = max(max_sum, sum);
        int l = k - 1;
        while (l >= 0) {
            sum -= arr[l];
            l--;
            sum += arr[r];
            max_sum = max(max_sum, sum);
            r--;
        }

        return max_sum;
    }
};