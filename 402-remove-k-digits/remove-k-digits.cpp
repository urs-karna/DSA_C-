class Solution {
public:
    string removeKdigits(string &num, int k) {
        int cnt=0;
        int n= num.size();
       stack<char>st;
       string s="";

       if(k==n) return "0";
       for(int i=0 ;i<n; i++) {


        while( !st.empty() && st.top()-'0' > num[i]- '0' && k >0 ) {
            st.pop();
            k--;
        }

           st.push(num[i]);

       }
      while(k>0 && !st.empty()) {
         st.pop();
         k--;
      }
       while(!st.empty()) {
        s +=st.top();
        st.pop();
       }
        reverse(s.begin(),s.end());
        int i=0;
        while( i <  n && s[i] == '0') {
            i++;
            if( s[i] != '0')  break;
        }
        cout<<i;
         s= s.substr(i,s.size());
         if(s.empty()) return "0";
        return s;
    }
};