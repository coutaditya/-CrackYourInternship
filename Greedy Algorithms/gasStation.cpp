// My ghisa-pita solution
// TC: O(n)  SC: O(1)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        int i = 0;
        while(i<n){
            if(gas[i]>=cost[i]){
                int j = (i+1)%n;
                int c = gas[i]-cost[i];
                
                while(j!=i){

                    c+=gas[j];
                    
                    int nx = (j+1)%n;
                    c-=(cost[j]);
                    if(c<0){
                        break;
                    }
                    j = nx;
                }
                
                if(i!=j){
                    j = (j+1)%n;
                    if(j<=i)
                        return -1;
                    else{
                        i = j;
                    }
                }
                else
                    return i;
            }
            else
                i++;
        }
        return -1;
    }
};


// Slightly better dikhne wala solution (same TC SC)
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

       int start = gas.size()-1;
       int end = 0;
       int sum = gas[start] - cost[start];
       while (start > end) {
          if (sum >= 0) {
             sum += gas[end] - cost[end];
             ++end;
          }
          else {
             --start;
             sum += gas[start] - cost[start];
          }
       }
       return sum >= 0 ? start : -1;
    }
};

