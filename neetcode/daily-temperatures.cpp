class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int length = temperatures.size();
        vector<int> answer(length,0);
        int arr[length];
        int idx=0;
        arr[idx++] = 0;
        int i=1;
        while(i<length){
            while(idx > 0 && temperatures[arr[idx-1]] < temperatures[i]){
                answer[arr[idx-1]] = i - arr[idx-1];
                idx--;
            }
            arr[idx++] = i;
            i++;
        }
        return answer;
    }
};