class Solution {
public:
     bool IsPalindrome(string s, int start, int end) {
        while(start <= end) {
            if( s[start++] != s[end--]) {
                return false;
            }
           
        }
         return true;
    }
    void FindEachSubSet(int idx, string s,vector<vector<string>> &ans,vector<string>SubSet)
    {     
          if(idx==s.size()) {
            ans.push_back(SubSet);
            return;
          }

          for(int i=idx;i<s.size();i++) {
            
           if( IsPalindrome(s,idx,i)) {
                     
                SubSet.push_back(s.substr(idx, i -idx+1));
                FindEachSubSet(i +1 , s,ans, SubSet);
                SubSet.pop_back();
           }

          }

    }
   
        vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>SubSet;

        FindEachSubSet(0,s,ans,SubSet);
        return ans;


    }
};