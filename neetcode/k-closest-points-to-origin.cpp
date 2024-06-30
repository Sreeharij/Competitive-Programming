class Solution {
public:
    struct compare{
        bool operator()(const vector<int>& a,const vector<int>& b){
            return a[0]*a[0] + a[1]*a[1] >  b[0]*b[0] + b[1]*b[1];
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,compare> pq(points.begin(),points.end());
        vector<vector<int>> answer;
        for(int i=0;i<k;i++){
            answer.push_back(pq.top());
            pq.pop();
        }
        return answer;
    }
};