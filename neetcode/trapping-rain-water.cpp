//O(n) time and O(n) space solution
class Solution {
public:
    int trap(vector<int>& height) {
        int length = height.size();
        vector<int> left_boundary(length,0);
        vector<int> right_boundary(length,0);
        int left_max = height[0];
        for(int i=1;i<length;i++){
            left_max = height[i] > left_max ? height[i] : left_max;
            left_boundary[i] = left_max;
        }
        int right_max = height[length-1];
        for(int i=length-2;i>=0;i--){
            right_max = height[i] > right_max ? height[i] : right_max;
            right_boundary[i] = right_max;
        }
        int answer = 0;
        for(int i=0;i<length;i++){
            int water = min(left_boundary[i],right_boundary[i]) - height[i];
            answer +=  water > 0 ? water : 0;
        }
        return answer;
    }
};

//O(n) time and O(1) space solution
class Solution {
public:
    int trap(vector<int>& height) {
        int length = height.size();
        if(length < 3)return 0;
        int answer = 0;
        int left_ptr = 1,right_ptr = length - 2;
        int left_max = height[0];
        int right_max = height[length-1];
        int water;
        while(left_ptr <= right_ptr){
            if(left_max <= right_max){
                water = left_max - height[left_ptr];
                left_max = max(left_max,height[left_ptr]);
                left_ptr++;
            }
            else{
                water = right_max - height[right_ptr];
                right_max = max(right_max,height[right_ptr]);
                right_ptr--;
            }
            answer += water > 0 ? water : 0;
        }

        return answer;
    }
};