int longestSubarrayWithSumK(vector<int> a, long long k) {
    long long sum_val = 0;
    int left = 0,right = 0;
    int answer = 0;
    for(right = 0;right < a.size();right++){
        sum_val += a[right];
        while(sum_val > k){
            sum_val -= a[left++];       //handles the case where left becomes equal to right
        }
        if(sum_val == k){
            answer = max(answer,right - left + 1);
        }
    }
    return answer;
}