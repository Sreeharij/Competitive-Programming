//time: O(n + mlogm + k) where m is the number of distinct element in nums.
//The below can also be achieved by using priority queue after creating the hash map
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> answer_arr(k,0);
        unordered_map <int,int> freq_arr;
        for(auto x:nums){
            freq_arr[x]++;
        }
        vector<pair<int,int>> sorted_values(freq_arr.begin(),freq_arr.end());
        sort(sorted_values.begin(),sorted_values.end(),compare);
        for(int i=0;i<k;i++){
            answer_arr[i] = sorted_values[i].first;
        }
        return answer_arr;
    }

    static bool compare(pair<int,int> a,pair<int,int> b){
        return a.second > b.second;
    }
};

//The below method incoorporates the concept of bucket sort to achieve the time compleixty of
// O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> answer_arr(k,0);
        unordered_map <int,int> freq_arr;
        vector<vector<int>> buckets(nums.size()+1);
        for(auto x:nums){
            freq_arr[x]++;
        }
        for(auto x:freq_arr){
            buckets[x.second].push_back(x.first); 
        }
        int idx=0;
        for(int i=nums.size();i>0;i--){
            for(auto x:buckets[i]){
                if(idx==k){
                    return answer_arr;
                }
                answer_arr[idx++] = x;   
            }
        }
        return answer_arr;
    }
};