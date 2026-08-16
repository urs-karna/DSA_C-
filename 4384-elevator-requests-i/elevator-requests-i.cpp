class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int total =0;
        int ele_pos =0;
        for(int i =0;i<requests.size();i++ ) {

          total += abs(ele_pos -requests[i]);
          ele_pos = requests[i];

        }
        return total;
    }
};