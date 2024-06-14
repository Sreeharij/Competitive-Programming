class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int smallest_size = INT_MAX;
        string answer;
        
        unordered_map<char,int> mp;
        int remaining_required_count = 0;

        int left_start = 0;
        for(auto x: t){
            remaining_required_count++;
            mp[x]++;
        }

        for(int right = 0;right < s.size();right++){
            char right_char = s[right];
            if(mp.count(right_char)){
                if(mp[right_char] > 0)remaining_required_count--;
                mp[right_char]--;

                bool all_covered = remaining_required_count == 0;

                while(all_covered && left <= right){
                    if(mp.find(s[left]) == mp.end()){
                        left++;
                        continue;
                    }
                    if(right - left + 1 < smallest_size){
                        smallest_size = right - left + 1;
                        left_start = left;
                    }
                    mp[s[left]]++;
                    if(mp[s[left]] > 0)remaining_required_count++;
                    left++;

                    all_covered = remaining_required_count == 0;
                }
            }
        }
        return smallest_size == INT_MAX ? "" : s.substr(left_start,smallest_size);
    }
};