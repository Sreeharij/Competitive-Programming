class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        set<pair<int,int>> st;
        for(int i=1;i<=k;i++)st.insert({0,i});
        int length = rolls.size();
        for(int i=length-1;i>=0;i--){
            int min_type = st.begin()->first;

            st.erase({min_type,rolls[i]});
            st.insert({min_type+1,rolls[i]});
        } 
        return st.begin()->first + 1;
    }
};