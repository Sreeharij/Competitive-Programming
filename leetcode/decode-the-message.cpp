class Solution {
public:
    string decodeMessage(string key, string message) {
        int counter = 0;
        unordered_map<char,char> hash_map;
        for(int i=0;i<key.size();i++){
            if(key[i] == ' '){
                continue;
            }
            if(hash_map.count(key[i]) == 0){
                hash_map[key[i]] = 'a' + counter;
                counter++;
            }
        }
        string answer = "";
        for(int i=0;i<message.size();i++){
            if(message[i] == ' '){
                answer += ' ';
            }
            else{
                answer += hash_map[message[i]];
            }
        }      
        return answer;
    }
};