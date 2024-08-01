class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int smallest_size = INT_MAX;
        int left_start = 0;
        int remaining_required_count = t.size();
        
        unordered_map<char,int> mp;
        for(auto x: t){
            mp[x]++;
        }

        for(int right = 0;right < s.size();right++){
            char right_char = s[right];
            if(mp.count(right_char)){
                if(mp[right_char] > 0)remaining_required_count--;
                mp[right_char]--;

                while(remaining_required_count == 0 && left <= right){
                    if(mp.count(s[left])){
                        if(right - left + 1 < smallest_size){
                            smallest_size = right - left + 1;
                            left_start = left;
                        }
                        
                        mp[s[left]]++;
                        if(mp[s[left]] > 0)remaining_required_count++;
                    }
                    left++;
                }
            }
        }
        return smallest_size == INT_MAX ? "" : s.substr(left_start,smallest_size);
    }
};