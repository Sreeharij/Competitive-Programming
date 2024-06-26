class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long count = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<hours.size();i++){
            count += mp[(24 - hours[i]%24)%24];
            mp[hours[i]%24]++;
        }
        return count;
    }
};