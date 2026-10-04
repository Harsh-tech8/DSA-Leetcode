class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totgas = 0 , totcost = 0;     
    //unqiue sloution 
        int start = 0 , currgas = 0;
        for(int i = 0;i<gas.size();i++){
            totgas += gas[i];
            totcost += cost[i];
            currgas += (gas[i]-cost[i]);
            if(currgas < 0){
                start = i+1;
                currgas = 0;
            }
        }
        if(totgas < totcost){
            return -1;
        }else{
        return start;
        }
    }
};