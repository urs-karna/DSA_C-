class Solution {
private: 
       int find_oper(string &s){
         int total = 0;
          int n = s.size(); 
        int i = 0, j = n-1;

        while( i < j) {

            if( s[i] == s[j]) {
                i++;
                j--;

            }
            else {
              int act_diff = abs(s[i] - s[j]);
              int rev_diff = abs(act_diff - 26);
              int min_diff = min(act_diff, rev_diff);
              total += min_diff;
             i++;
             j--;

            }
        }

         return total;   


       }

public:
    int minOperations(string s) {

        string org_str = s;
         int total = INT_MAX;
         int n = s.size(); 
        
        for(int i =0 ; i<n ;i++) {
          
          reverse(s.begin(), s.begin()+i);
          reverse(s.begin()+i,s.end());
          reverse(s.begin(),s.end());
          int total_opr = i  + find_oper(s);
         total = min( total,total_opr );
          s = org_str;

        }
   return total;
             
    }
};