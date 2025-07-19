class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, max_len = 0, max_freq = 0;
        vector<int> hash_arr(26, 0);
        int n = s.size();
        while (r < n) {
            hash_arr[s[r] - 'A']++;

            max_freq = max(max_freq, hash_arr[s[r] - 'A']);

            // int changes= (r-l+1) - max_freq;

            while ((r - l + 1) - max_freq > k) {

                hash_arr[s[l] - 'A']--;
                // l++;

                // max_freq=0;
                // for(int i=0;i<26;i++) max_freq= max(max_freq, hash_arr[i]);
                l++;
            }

            // if(r-l+1 <= k)
            max_len = max(max_len, r - l + 1);

            r++;
        }

        return max_len;
    }
};