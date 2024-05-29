//Method 1
// O(n*mlogm) where n is the number of words and m is the average length of each word

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        int counter = 0;
        string word;
        unordered_map <string,int> freq_map;
        for(int i=0;i<strs.size();i++){
            word = strs[i];
            sort(word.begin(),word.end());
            if(freq_map.find(word)!=freq_map.end()){
                answer[freq_map[word]].push_back(strs[i]);
            }
            else{
                vector<string> temp_vector;
                temp_vector.push_back(strs[i]);
                answer.push_back(temp_vector);
                freq_map[word] = counter++;
            }
        }
        return answer;
    }
};

//Method 2
// O(n * (m+26))~= O(n*m) where n is number of words and m is average length of each word
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<string,vector<string>> answer_map;

        for(int i=0;i<strs.size();i++){
            int char_counter[26] = {0};
            for(auto x:strs[i]){
                char_counter[x-'a']++;
            }
            string temp_string;

            for(auto x:char_counter){
                temp_string += x;
            }

            answer_map[temp_string].push_back(strs[i]);
        }
        for(auto x:answer_map){
            answer.push_back(x.second);
        }
        return answer;
    }
};