class Solution {
public:
       
    bool lemonadeChange(vector<int>& bills) {
      //  sort(bills.begin(),bills.end()) ;
          int five=0, ten=0;
           int n=bills.size();
        for(int i=0;i<n;i++) {
            if( bills[i]== 5) five +=1;

            else if( bills[i]==10 ) {

                if( five >=1) {
                    five -=1;
                    ten +=1;
                }
                else  return false ;
            }

            else {
                  
                  if( five >=1 && ten >=1) {
                    five -=1;
                    ten -=1;

                  }
                  else if( five >=3) {
                    five -=3;
                  }
                  else return false;

            }

        }
        return true;

    }
};