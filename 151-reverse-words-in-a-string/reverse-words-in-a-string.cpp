class Solution {
public:
    string reverseWords(string s) {
        string res= "";
        int n = s.size();
        reverse(s.begin(), s.end());

        int start=0;
        int end = 0;
while(start < s.size()) {
        while (start < n && s[start] == ' ' ) start++;
        if(start >= n) break;
         end = start;
        while(end < n && s[end] != ' ' ) end++;

        string temp = s.substr(start, end-start);
        reverse(temp.begin(), temp.end());

        if(!res.empty()) res += ' ';
        res += temp;
        start = end;

    }

    return res;
    }
    
};