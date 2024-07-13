class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        while(left < right){
            while((s[left] < 65 || s[left] > 90) && (s[left] < 97 || s[left] > 122) && (s[left]-'0' > 9 || s[left]-'0' < 0 )){
                left++;
                if(left >= right)break;
            }
            while((s[right] < 65 || s[right] > 90) && (s[right] < 97 || s[right] > 122) && (s[right]-'0' > 9 || s[right]-'0' < 0)){
                right--;
                if(right <= left) break;
            }
            if(left > right)return true;
            if(tolower(s[left]) != tolower(s[right]))return false;
            left++;
            right--;
        }
        return true;
    }
};