class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, max_len = 0, max_freq = 0;
        vector<int> hash_arr(26, 0);
        int n = s.size();
        while (r < n) {
            hash_arr[s[r] - 'A']++;

            max_freq = max(max_freq, hash_arr[s[r] - 'A']);

            if ((r - l + 1) - max_freq > k) {

                hash_arr[s[l] - 'A']--;

                l++;
                // no need no check the max_freq again
            }

            max_len = max(max_len, r - l + 1);

            r++;
        }

        return max_len;
    }
};