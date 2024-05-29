class Solution {
    public:
    bool isAnagram(string s, string t) {
        int range = 26;
        int hash_arr[range] = {0};
        for(int i=0;i<s.size();i++){
            hash_arr[(int)s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++){
            if(t[i]>=min && t[i]<=max){
                hash_arr[(int)t[i]-min]--;
                if (hash_arr[(int)t[i]-min]==-1){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};