//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    pair<int,int> answer = {-1,-1};
    int current_floor = -1;
    int current_ceil = INT_MAX;
   for(int i=0;i<n;i++){
       if(arr[i]==x){
           answer.first = arr[i];
           answer.second = arr[i];
           return answer;
       }
       else if(arr[i] < x){
           if(arr[i] > current_floor){
               current_floor = arr[i];
           }
       }
       else{
           if(arr[i] < current_ceil){
               current_ceil = arr[i];
           }
       }
   }
   answer.first = current_floor;
   if(current_ceil == INT_MAX){
       answer.second = -1;
   }
   else{
       answer.second = current_ceil;
   }
   return answer;
}
