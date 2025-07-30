class Solution {
public:
  
    int jump(vector<int>& arr) {
         int n=arr.size();
         
         if(n==1 ) return 0;
          int jump=0;
          int l=0,r=0;
          while(r< n-1)  {
          int fartest=0;    
          for(int i=l;i<=r;i++)  {
             
              fartest= max(i+arr[i],fartest);
              
          }
           l = r+1;
           r=fartest;
           jump +=1;
          }
          return jump;
    }
};
