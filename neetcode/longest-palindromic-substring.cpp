class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        int size = 1;
        string answer = string(1,s[0]);
        for(int i=0;i<length-1;i++){       //LOOT FINISHES at i < length - 1 since this is correct for both EVEN and ODD length pallindros
            int l = i,r = i;
            while(l >= 0 && r <= length-1 && s[l] == s[r]){
                l--;
                r++;
            }
            if(r - l - 1 > size){   // r-l+1 is size of substring had r and l been both part of the substring. so do r-l+1-2 = r-l-1
                size = r - l - 1;
                answer = s.substr(l+1,size);
            }

            l = i,r=i+1;
            while(l >= 0 && r <= length-1 && s[l] == s[r]){
                l--;
                r++;
            }
            if(r - l - 1 > size){
                size = r - l - 1;
                answer = s.substr(l+1,size);
            }
        }
        return answer;
    }
};