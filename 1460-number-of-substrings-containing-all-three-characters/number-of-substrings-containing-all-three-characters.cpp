class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt_sub = 0;
        vector<int> hash_arr(3, -1);
        for (int i = 0; i < n; i++) {
            hash_arr[s[i] - 'a'] = i;
            if (hash_arr[0] > -1 && hash_arr[1] > -1 && hash_arr[2] > -1) {

                cnt_sub += min({hash_arr[0], hash_arr[1], hash_arr[2]}) + 1;
            }
        }
        return cnt_sub;
    }
};