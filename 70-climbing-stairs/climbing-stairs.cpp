class Solution {
public:

//    int fib( int n, vector<int> &Dp) {

//     if( n <= 2) return n;

//     else if(Dp[n] != -1) return Dp[n];
//      else {
//         return Dp[n] = fib(n-1,Dp) + fib(n-2,Dp); 
//      }

//    }

  
  //  --> tabulization 
    // int climbStairs(int n) {
    //     vector<int>Dp(n+1,-1);
    //    // int ans = fib(n,Dp);
    //    Dp[0] = 0;
    //    Dp[1] = 1;
    //    Dp[2] = 2;

    //    for(int i =3;i<=n;i++) {

    //      Dp[i] = Dp[n-1] + Dp[n-2];
    //    }
    //    cout<<Dp[n];
    //     return Dp[n];

    int climbStairs(int n) {
        int prev =2;
        int prev2 = 1;
     if( n== 1) return prev2;

       

        for(int i =3;i<=n;i++) {

            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};