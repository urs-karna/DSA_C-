class Solution {
public:
    int vowelConsonantScore(string s) {
        int cnt_c= 0;
        int cnt_v= 0;
        for(int i =0 ; i< s.size();i++) {

            if( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ) {

               cnt_v++;

            }
           
            else  if( isalpha(s[i]))cnt_c++;
        }
     cout<<"v" << cnt_v;
     cout<<"c"<<cnt_c;
        if(cnt_c > 0 ) {
            return floor(cnt_v/cnt_c);
        }
        return 0;
    }
};