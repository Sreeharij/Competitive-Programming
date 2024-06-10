//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void backtrack(vector<int>& answer,vector<int>& arr,int& sum_val,int start){
        answer.push_back(sum_val);
        for(int i=start;i<arr.size();i++){
            sum_val += arr[i];
            backtrack(answer,arr,sum_val,i+1);
            sum_val -= arr[i];
        }
    }
  
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> answer;
        int sum_val=0;
        backtrack(answer,arr,sum_val,0);
        return answer;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends