class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        
        int n= arr.size();
        long long  sum=0;
        

        for(int i=0;i<n;i++) {
            
            int min_ele=arr[i];
            int max_ele= arr[i];
            for(int j=i;j<n;j++) {
               min_ele= min( min_ele, arr[j]);
               max_ele= max(max_ele, arr[j]);
               long long  range=  (long long )(max_ele - min_ele);
               sum +=  range;

            }
        }
     return sum;
        
    }
};