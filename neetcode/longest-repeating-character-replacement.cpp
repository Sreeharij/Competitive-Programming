class Solution {
public:
    int characterReplacement(string s, int k) {
        int length = s.size();
        vector<int> freq_table(26,0);
        int left = 0;
        int answer = INT_MIN;
        int current_max_count = 0;
        for(int right = 0;right<length;right++){
            freq_table[s[right] - 'A']++;
            current_max_count = max(current_max_count,freq_table[s[right] - 'A']);
            while( (right - left + 1) - current_max_count > k){
                freq_table[s[left] - 'A']--;
                left++;
            }
            answer = max(answer,right - left + 1);
        }

        return answer;     
    }
};








