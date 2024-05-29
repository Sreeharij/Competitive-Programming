class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.size();
        if(length<=1){
            return length;
        }
        int left = 0;
        int right = 0;
        int repetition_count = 0;
        int current_max_length = 1;
        unordered_map <int,int> freq_arr;
        freq_arr[s[0]] = 1;
        while(right+1<length){
            right++;       
            if(repetition_count==0 && freq_arr[s[right]] == 0){
                freq_arr[s[right]] = 1;
                current_max_length++;
            }
            else{
                freq_arr[s[right]]++;
                repetition_count += freq_arr[s[right]] > 1 ? 1 : 0;
                repetition_count -= freq_arr[s[left]] > 1 ? 1 : 0;
                freq_arr[s[left]]--;
                left++;
            }
        }
        return current_max_length;
    }
};