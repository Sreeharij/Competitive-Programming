class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool left = false,mid = false,right = false;
        
        for(int i=0;i<triplets.size();i++){
            if(triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2])continue;
            left = triplets[i][0] == target[0] ? true : left;
            mid = triplets[i][1] == target[1] ? true : mid;
            right = triplets[i][2] == target[2] ? true : right; 
        }
        return left && mid && right;
    }
};