class Solution {
public:
    vector<int> partitionLabels(string s) {
        int arr[26][2];
        for(int i=0;i<26;i++){
            arr[i][0] = -1;
            arr[i][1] = -1;
        }
        for(int i=0;i<s.size();i++){
            if(arr[s[i]-'a'][0] == -1){
                arr[s[i]-'a'][0] = i;
            }
            arr[s[i]-'a'][1] = i;
        }
        vector<vector<int>> intervals;
        for(int i=0;i<26;i++){
            if(arr[i][0] == -1)continue;
            intervals.push_back({arr[i][0],arr[i][1]});
        }
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> partitions;
        partitions.push_back(intervals[0]);
        int idx = 0;
        for(int i=1;i<intervals.size();i++){
            if(partitions[idx][1] >= intervals[i][0]){
                partitions[idx][1] = max(partitions[idx][1],intervals[i][1]);
            }
            else{
                partitions.push_back(intervals[i]);
                idx++;
            }
        }
        vector<int> answer(partitions.size(),0);
        for(int i=0;i<partitions.size();i++){
            answer[i] = partitions[i][1] - partitions[i][0] + 1;
        }
        return answer;
    }
};