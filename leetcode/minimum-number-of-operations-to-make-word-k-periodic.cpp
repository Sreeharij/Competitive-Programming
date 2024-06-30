class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int> mp;
        for(int i=0;i<word.size();i=i+k){
            mp[word.substr(i,k)]++;
        }
        int max_freq_word = 0;
        for(auto it: mp){
            max_freq_word = max(max_freq_word,it.second);
        }
        return word.size()/k - max_freq_word;
    }
};
