class Solution {
public:
    string defangIPaddr(string address) {
        string answer = "";
        for(int i=0;i<address.size();i++){
            if(address[i] != '.'){
                answer += address[i];
            }
            else{
                answer += "[.]";
            }
        }
        return answer;
    }
};