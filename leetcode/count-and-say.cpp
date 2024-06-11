class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        vector<string> arr(n+1);
        arr[1] = "1";
        arr[2] = "11";
        for(int i=3;i<=n;i++){
            string previous_word = arr[i-1];
            string new_word = ""; 
            int count = 1;
            int prev_size = previous_word.size();
            for(int j=1;j<prev_size;j++){
                if(previous_word[j] == previous_word[j-1]){
                    count++;
                }
                else{
                    new_word += to_string(count) + previous_word[j-1];
                    count = 1;
                }
            }
            new_word += to_string(count) + previous_word[prev_size-1];
            arr[i] = new_word;
        }
        return arr[n];
    }
};