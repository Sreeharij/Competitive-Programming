class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t answer= 0;
        for(int i=0;i<32;i++){
            answer = answer | ((1 & n) << (32 - i - 1));
            n = n >> 1;
        }
        return answer;
    }
};

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t answer= 0;
        for(int i=0;i<32;i++){
            answer = answer << 1;
            answer = answer | (1 & n);
            n = n >> 1;
        }
        return answer;
    }
};