class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
         int m=t.size();
        if( s.size() < t.size()) return "";
         
         int min_len=INT_MAX;
         int start_idx=-1;
         int cnt=0;
         int arr[256] = {0};

         for(int i=0;i<m;i++) arr[t[i]]++;

         int l=0;
         int r=0;
         while( r< n) {
          
          if( arr[s[r]] > 0) cnt += 1;

             arr[s[r]]--;
             
             while(cnt==m) {
                if( r-l+1 < min_len)  {

                    min_len= r-l+1;
                    start_idx=l;
                }
                  arr[s[l]]++;
                  if( arr[s[l]] > 0) cnt-= 1;

                  l++;

             }
             r++;
         }

         return start_idx==-1 ? "": s.substr(start_idx,min_len);

         
    }
};