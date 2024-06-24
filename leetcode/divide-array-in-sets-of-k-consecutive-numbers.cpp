class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int length = nums.size();
        if(length%k != 0)return false;
        int groups = length/k;
        int number;
        map<int,int> mp;
        for(auto x: nums)mp[x]++;
        while(groups--){
            number = mp.begin()->first;
            for(int i=0;i<k;i++){
                if(mp.count(number+i)==0)return false;
                mp[number+i]--;
                if(mp[number+i]==0)mp.erase(number+i);
            }
        }

        return true;
    }
};