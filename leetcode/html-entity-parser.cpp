class Solution {
public:
    string entityParser(string text) {
        int start = -1;
        int end = start;
        int i=0;
        string replace_string = "";
        unordered_map<string,char> mp = {
            {"&quot;", '"'},
            {"&amp;", '&'},
            {"&gt;", '>'},
            {"&lt;", '<'},
            {"&frasl;", '/'}
        };
        while(i < text.size()){
            if(text[i] == '&'){
                start = i;
            }
            else if(text[i] == ';'){
                end = i;
                if(start != -1){
                    string word = text.substr(start,end-start+1);
                    if(mp.count(word)){
                        replace_string = mp[word];
                        text.replace(start,end-start+1,replace_string);
                        i = start+1;
                        end = start+1;
                        start++;
                    }
                    else if(word == "&apos;"){
                        text.replace(start,end-start+1,"'");
                        i = start+1;
                        end = start+1;
                        start++;
                    }
                }
            }
            i++;
        }
        return text;
    }
};