class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        if (n == 0)
            return 0;

        int idx = 0;
        int sign = 1;
        long ans = 0;

        while (idx < n && s[idx] == ' ')
            idx++;
      
        if (idx < n && s[idx] == '-') {
            sign = -1;
            idx++;
        }
       else  if (idx < n && s[idx] == '+') {
            sign = 1;
            idx++;
        }

        while (idx < n) {
            if (s[idx] >= '0' && s[idx] <= '9') {
                ans = ans * 10 + (s[idx] - '0');
                if (ans > INT_MAX && sign == -1)
                    return INT_MIN;
                if (ans > INT_MAX)
                    return INT_MAX;
                idx++;
            } else
                break;
        }

        ans = ans * sign;
        return ans;
    }
};