class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3)return false;
        bool in_range;
        bool vowel = false,consonent = false;
        for(char x: word){
            in_range = (x <= 57 && x >= 48) || (x <= 90 && x >= 65) || (x <= 122 && x >= 97);
            if(!in_range)return false;
            if(tolower(x) == 'a' || tolower(x) == 'e' || tolower(x) == 'i' || tolower(x) == 'o' || tolower(x) == 'u'){
                vowel = true;
            }
            else if(!(x <= 57 && x >= 48)){
                consonent = true;
            }
            
        }
        return vowel && consonent;
    }
};