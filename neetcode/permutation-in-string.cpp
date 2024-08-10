class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1_size = s1.size();
        if(s1_size > s2.size())return false;
        
        vector<int> s1_count(26,0);
        vector<int> s2_count(26,0);
        for(int i=0;i<s1_size;i++){
            s1_count[s1[i]-'a']++;
            s2_count[s2[i]-'a']++;
        }
        if(s1_count == s2_count) return true;

        for(int i=s1_size;i<s2.size();i++){
            s2_count[s2[i]-'a']++;
            s2_count[s2[i-s1_size] - 'a']--;
            if(s1_count == s2_count) return true;
        }
        return false;
    }
};