class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
            long long MOD = (int) 1e9 +7;
            int n= arr.size();
            long long cnt=0;

            vector<int>NSE(n),PSEE(n);
            stack<int> st;
            
           //NSE
            for(int i=n-1;i>=0;i--) {
                while( !st.empty() && arr[st.top()] >= arr[i] ) {
                    st.pop();
                }

                if(st.empty())  NSE[i]= n;
                else {
                    NSE[i]= st.top();
                }
                st.push(i);
            }
              st = stack<int>();
            //pSEE 
            for(int i=0;i<n;i++) {

                while( !st.empty() &&  arr[st.top()] > arr[i]) {
                    st.pop();
                }
                if(st.empty()) {
                    PSEE[i] = -1;
                }
                else {
                    PSEE[i] = st.top();
                }
                st.push(i);
            }

           
           for(int i=0;i<n;i++) {
            long long left=  NSE[i] -i;
            long long right = i- PSEE[i] ;
            long long  contribution =  ((left * right ) * arr[i]) % MOD ;
            cnt =  (cnt + contribution) %MOD; 
           }
        return (int)cnt;    
    }
};