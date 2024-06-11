class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end(),greater<int>());
        sort(s.begin(),s.end(),greater<int>());
        int count = 0;
        int idx = 0;
        for(int i=0;i<g.size();i++){
            if(idx >= s.size())break;
            if(g[i] <= s[idx]){
                count++;
                idx++;
            }
        }
        return count;
    }
};