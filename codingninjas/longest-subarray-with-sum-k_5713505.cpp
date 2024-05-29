#include <bits/stdc++.h> 
int getLongestSubarray(vector<int> nums,int k) {
    int answer = 0;
    unordered_map <int,int> mp;
    long long sum_val = 0;

    for(int i=0;i<nums.size();i++){
        sum_val += nums[i];
        if(mp.find(sum_val)  == mp.end()){
            mp[sum_val] = i;
        }
        if(mp.find(sum_val - k) != mp.end()){
            answer = max(answer,i - mp[sum_val - k]);
        }
        if(sum_val == k){
            answer = max(answer,i+1);
        }
    }
    return answer;
}