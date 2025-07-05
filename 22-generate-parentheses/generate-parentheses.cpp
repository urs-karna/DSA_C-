class Solution {
public:
    void generateEach(int n,vector<string> &res,string curr,int open,int close) {
        
        if( curr.size() == n*2) {
            res.push_back(curr);
            return;
        }
        if(open < n) {
             generateEach(n,res,curr + '(',open+1,close);
        }
     if(close < open) {
             generateEach(n,res,curr + ')',open ,close+1);
        }

    }  
    vector<string> generateParenthesis(int n) {
       
       vector<string> res;
      // string curr;
         generateEach( n,res,"",0,0);
         return res;
        
    }
};