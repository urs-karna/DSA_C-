class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        
        if(n==0) return 0;
        if(n==1) return 1;
        int long_substr=1;
        for(int i=0;i<n;i++) {
              int  len_substr=0;
              unordered_map<int,int>mpp;
            for( int j=i;j<n;j++) {
                  
                 if(mpp.find(s[j]) == mpp.end()) {
                    mpp[s[j]]++;
                    len_substr++;
                 }
                 else break;

            } 
            long_substr= max(long_substr, len_substr);
        }
        return long_substr;
    }
};