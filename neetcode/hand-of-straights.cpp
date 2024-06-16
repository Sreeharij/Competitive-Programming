//O(nlogn) time solution
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int length = hand.size();
        if(length%groupSize != 0) return false;
        map<int,int> mp;
        int groups = length/groupSize;
        for(auto x: hand){
            mp[x]++;
        }
        while(groups){
            int number = mp.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(mp.count(number+i) == 0)return false;
                mp[number+i]--;
                if(mp[number+i] == 0)mp.erase(number+i);   
            }
            groups--;
        }
        return true;
    }
};

//O(n) time solution
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int length = hand.size();
        if(length%groupSize != 0) return false;
        sort(hand.begin(),hand.end());
        unordered_map<int,int> freq;

        for(int number: hand)freq[number]++;

        for(int number: hand){
            if(freq[number] == 0)continue;

            for(int i=0;i<groupSize;i++){
                if(freq[number+i] == 0)return false;
                freq[number+i]--;
            }
        }
        return true;
    }
};