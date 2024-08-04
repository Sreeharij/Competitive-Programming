class Solution {
public:
    int countSubstrings(string s) {
        int length = s.size();
        int count = 0;
        for(int i=0;i<length;i++){
            int l = i,r = i;
            while(l >= 0 && r < length && s[l] == s[r]){
                count++;
                l--;
                r++;
            }

            l = i,r=i+1;
            while(l >= 0 && r < length && s[l] == s[r]){
                count++;
                l--;
                r++;
            }
        }
        return count;
    }
};