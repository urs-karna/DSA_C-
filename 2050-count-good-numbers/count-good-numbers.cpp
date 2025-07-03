class Solution {
public:
long long MOD= 1e9 + 7;
long long power(long long x, long long n) {
  
    if(n==0) return 1;
    long long ans= power(x,n/2);
    if(n%2==0) {
        ans= ans * ans;
       return  ans = ans% MOD;
    }
    else {
        ans = x* ans * ans ;
       return  ans= ans % MOD;

    }
}
    int countGoodNumbers(long long n) {
         long long MOD= 1e9 + 7;
         long long even=0,odd=0;

            even= n/2 + n%2;
            odd=n/2;

         long long res= power(5,even) * power(4,odd);

            return res % MOD;
        
    }
};