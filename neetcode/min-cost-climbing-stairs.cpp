//METHOD 1 - DP
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int length = cost.size();
        int arr[length];
        arr[0] = cost[0];
        arr[1] = cost[1];
        for(int i=2;i<length;i++){
            if(arr[i-1] + cost[i] < arr[i-2] + cost[i]){
                arr[i] = arr[i-1] + cost[i];
            }
            else{
                arr[i] = arr[i-2] + cost[i];
            }
        }
        int answer = arr[length-1] < arr[length-2] ? arr[length-1] : arr[length-2];
        return answer;
    }
};




//METHOD 2 SPACE OPTIMISED
//CALCULATING ON THE GO - NOT STORING VALUES

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int length = cost.size();
        int first = cost[0];
        int second = cost[1];
        int temp;
        for(int i=2;i<length;i++){
            if(first + cost[i] < second + cost[i]){
                temp = first + cost[i];
            }
            else{
                temp = second + cost[i];
            }
            first = second;
            second = temp;
        }
        int answer = first < second ? first : second;
        return answer;
    }
};