//OPTISED SOLUTION USING SLIDING WINDOW CONCEPT
vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
    vector<vector<int>> answer;
    int length = a.size();
    int left = 0,right = 0;
    long long current_sum = 0;
    
    while(right < length ){
        current_sum += a[right];

        while(left<=right && current_sum > k){
            current_sum -= a[left++];
        }

        if(current_sum == k){
            vector<int> subarray(a.begin() + left,a.begin() + right + 1);
            answer.push_back(subarray);
        }
        right++;
    }
    return answer;
}