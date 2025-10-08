class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
      long gas_sum = accumulate(gas.begin(), gas.end(),0);
      long cost_sum = accumulate(cost.begin(), cost.end(),0);
       
       if(cost_sum > gas_sum) return -1;

       int sum =0;
       int index = 0 ;
      
      for(int i =0 ; i < gas.size();i++) {

        sum  += gas[i];

        sum -= cost[i];

        if(sum < 0 ) {
            sum = 0;
             index = i +1;
        }
      }
   return index;
           
    }
};