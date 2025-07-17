class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        
        if(n==0) return 0;
        if(n==1) return 1;
        int long_substr=1;
        unordered_map<char ,int>mp;
        int l=0,r=0;
         while( r < n) {
           if( mp.find(s[r]) != mp.end() ){    
             if(mp[s[r]] >= l ) {
               l= mp[s[r]] +1;
             }
           }

           int  len=  r-l+1;
           long_substr= max(long_substr, len);

           mp[s[r]] = r;
           r++;

         }
       return  long_substr;
    }
};