class Solution {
public:
    int get_bits(int x){
        int count = 0;
        while(x){
            x = x&(x-1);
            count++;
        }
        return count;
    }

    long long countExcellentPairs(vector<int>& nums, int k) {
        long long answer = 0;        
        unordered_set<int> unique_elements;
        for(auto x: nums)unique_elements.insert(x);
        vector<int> bits;
        for(auto x: unique_elements){
            bits.push_back(get_bits(x));
        }
        int length = bits.size();
        int freq[32] = {0};
        for(int i=0;i<length;i++){
            freq[bits[i]]++;
        }
        int idx = 0;
        for(int i=0;i<32;i++){
            for(int j=0;j<freq[i];j++){
                bits[idx++] = i;
            }
        }
        int left = 0;
        int right = length-1;
        for(auto x:bits)cout<<x<<" ";
        while(left <= right){
            if(bits[left] + bits[right] >= k){
                answer += (right-left)*2 + 1;
                right--;
            }
            else{
                left++;
            }
        }

        
        return answer;
    }
};
