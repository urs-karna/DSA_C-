class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
      int n= arr.size();
      if(n==1) return arr[n-1];
      int max_area=0;
       stack<int>st;
//pse ,nse
      for(int i =0;i<n;i++)  {
          while(  !st.empty() && arr[st.top()] > arr[i]) {

                int ele= arr[st.top()];
                st.pop();
               int  pse= st.empty() ? -1 : st.top();
               int  nse=i;
                max_area= max( max_area,(nse - pse -1) *ele );   

          }
          st.push(i);

      }

      while(!st.empty() )  {
        int ele= arr[st.top()];
        st.pop();
        int nse=n;
        int pse= st.empty() ? -1 : st.top();
        max_area= max(max_area, (nse-pse-1) * ele);
        
      }
      return max_area;

    }
};