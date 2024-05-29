//Below solution complexity is O(n^2*m) where n is length of wordlist and m is max_length of a single word
class Solution {
public:
    bool single_difference(string& first,string& second,int word_length){
        int diff_count=0;
        for(int i=0;i<word_length;i++){
            if(first[i] != second[i]){
                diff_count++;
            }
        }
        if(diff_count != 1) return false;
        return true;
    }

    int get_shortest_distance(string& beginWord,string& endWord,unordered_map<string,vector<string>>& graph){
        if(graph.find(endWord) == graph.end()){
            return 0;
        }
        unordered_map<string,int> visited;
        for(auto x: graph){
            visited[x.first] = -1;
        }
        queue<string> q;
        q.push(beginWord);
        visited[beginWord] = 1;

        while(!q.empty()){
            string current_word = q.front();
            q.pop();
            for(auto word: graph[current_word]){
                if(visited[word] == -1){
                    visited[word] = visited[current_word] + 1;
                    q.push(word);
                }
            }
        }
        if(visited[endWord] == -1) return 0;
        return visited[endWord];
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int shortest_length = 0;
        unordered_map<string,vector<string>> graph;
        int word_length = beginWord.size();
        int wordlist_size = wordList.size();
        for(int i=0;i<wordlist_size;i++){
            graph[wordList[i]] = vector<string>();
            for(int j=0;j<wordlist_size;j++){
                if(i==j) continue;
                if(single_difference(wordList[i],wordList[j],word_length)){
                    graph[wordList[i]].push_back(wordList[j]); 
                }
            }
        }
        
        graph[beginWord] = vector<string>();
        for(auto word: wordList){
            if(single_difference(beginWord,word,word_length)){
                graph[beginWord].push_back(word);
                graph[word].push_back(beginWord);
            }
        }
        shortest_length = get_shortest_distance(beginWord,endWord,graph);
        return shortest_length;
    }
};

//below implementation takes O(n*m) for making patterns_map, O(26*2/2 * n*m) for building graph from it, O(n^2) for doing bfs => O(n^2)
class Solution {
public:
    void get_patterns_generated(string& word, unordered_map<string,vector<string>>& patterns_map,int word_length){
        string key = word;
        for(int i=0;i<word_length;i++){
            key[i] = '*';
            patterns_map[key].push_back(word);
            key[i] = word[i];
        }
    }

    int get_shortest_distance(string& beginWord,string& endWord,unordered_map<string,vector<string>>& graph){
        if(graph.find(endWord) == graph.end()){
            return 0;
        }
        unordered_map<string,int> visited;
        for(auto x: graph){
            visited[x.first] = -1;
        }
        queue<string> q;
        q.push(beginWord);
        visited[beginWord] = 1;

        while(!q.empty()){
            string current_word = q.front();
            q.pop();
            for(auto word: graph[current_word]){
                if(visited[word] == -1){
                    visited[word] = visited[current_word] + 1;
                    q.push(word);
                }
            }
        }
        if(visited[endWord] == -1) return 0;
        return visited[endWord];
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool present = false;
        for(auto word: wordList){
            if(word == endWord){
                present=true;
                break;
            }
        }
        if(!present) return 0;

        int shortest_length = 0;
        unordered_map<string,vector<string>> graph;
        int word_length = beginWord.size();
        int wordlist_size = wordList.size();
        
        unordered_map<string,vector<string>> patterns_map;
        for(int i=0;i<wordlist_size;i++){
            get_patterns_generated(wordList[i],patterns_map,word_length);
        }
        get_patterns_generated(beginWord,patterns_map,word_length);
        for(auto pair: patterns_map){
            int length = pair.second.size();
            for(int i=0;i<length;i++){
                for(int j=i+1;j<length;j++){
                    graph[pair.second[i]].push_back(pair.second[j]);
                    graph[pair.second[j]].push_back(pair.second[i]);
                }
            }
        }
        shortest_length = get_shortest_distance(beginWord,endWord,graph);
        return shortest_length;
        return 10;
    }
};


//Below implementation takes O(n*m*26)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(st.find(endWord) == st.end()){
            return 0;
        }        
        int word_length = beginWord.size();
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int distance = q.front().second;
            q.pop();
            if(word == endWord){
                return distance;
            }
            for(int i=0;i<word_length;i++){
                char original = word[i];
                for(char x = 'a';x<='z';x++){
                    word[i] = x;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,distance+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};