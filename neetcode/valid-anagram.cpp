class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_length = s.length();
        int t_length = t.length();
        if (s_length!=t_length){
            return false;
        }
        int min=s[0],max=s[0];
        for(int i=0;i<s_length;i++){
            if (s[i]>max){
                max = s[i];
            }
            if (s[i]<min){
                min = s[i];
            }
        }
        int range = max - min + 1;
        int hash_arr[range];
        for(int i=0;i<range;i++){
            hash_arr[i] = 0;
        }
        for(int i=0;i<s_length;i++){
            hash_arr[(int)s[i]-min]++;
        }

        for(int i=0;i<s_length;i++){
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