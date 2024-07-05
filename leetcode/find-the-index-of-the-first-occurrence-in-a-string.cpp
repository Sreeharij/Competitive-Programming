class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystack_length = haystack.size();
        int needle_length = needle.size();
        for(int i=0;i<=haystack_length-needle_length;i++){
            int j=0;
            while(j < needle_length && haystack[i+j] == needle[j])j++;
            if(j == needle_length) return i;
        }
        return -1;
    }
};