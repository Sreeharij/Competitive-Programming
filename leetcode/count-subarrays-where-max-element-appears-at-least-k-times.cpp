class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long answer = 0;
        int max_val = INT_MIN;

        for(auto x:nums)max_val = max(max_val,x);
        unordered_map<int,int> mp;
        
        int start = 0;
        int length = nums.size();
        
        for(int i=0;i<length;i++){
            mp[nums[i]]++;

            while(mp[max_val] == k){
                mp[nums[start]]--;
                answer += length - i;
                start++;
            }
        }
        return answer;
    }
};