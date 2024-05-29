class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int absolute_max = 0;
        for(int i=0;i<sentences.size();i++){
            int current_words = 0;
            for(int j=0;j<sentences[i].size();j++){
                if(sentences[i][j] == ' '){
                    current_words++;
                }
            }
            current_words += 1;
            absolute_max = absolute_max > current_words ? absolute_max : current_words;
        }
        return absolute_max;
    }
};