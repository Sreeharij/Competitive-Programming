class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int length = gas.size();
        int total=0;
        for(int i=0;i<length;i++){
            total += gas[i] - cost[i];
        }
        if(total < 0) return -1;
        int start_idx=0;
        total = 0;
        for(int i=0;i<length;i++){
            total += gas[i] - cost[i];
            if(total < 0){
                total = 0;
                start_idx = i+1;
            }
        }


        return start_idx;
    }
};