class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int cars = position.size();
        double time;
        map<int,double> mp;
        for(int i=0;i<cars;i++){
            time = (double)(target - position[i])/speed[i];
            mp[position[i]] = time;
        }        
        stack<double> stk;
        for(auto it:mp){
            while(!stk.empty() && it.second >= stk.top()){
                stk.pop();
            }
            stk.push(it.second);
        }

        return stk.size();
    }
};

