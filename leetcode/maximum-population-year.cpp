class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int answer = 0;
        int population = 0;
        for(int i=1950;i<=2050;i++){
            int temp = 0;
            for(auto x: logs){
                if(x[0] <= i)temp++;
                if(x[1] <= i)temp--;
            }
            if(temp > population){
                population = temp;
                answer = i;
            }
        }
        return answer;
    }
};