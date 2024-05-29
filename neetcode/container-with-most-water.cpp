class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0,end = height.size()-1;

        int current_water = 0;
        int max_water = 0;
        int breadth = 0;
        while(start<end){
            breadth = height[start] < height[end] ? height[start] : height[end];
            current_water = (end - start) * breadth;
            max_water = max_water >  current_water ? max_water : current_water;

            if(height[start] <= height[end]){
                start += 1;
            }
            else if(height[start] > height[end]){
                end -= 1;
            }
        }
        return max_water;
    }
};