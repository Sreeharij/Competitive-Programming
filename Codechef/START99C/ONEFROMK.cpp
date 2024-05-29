#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        long long answer_arr[n];
        long long temp_sum = 0;
        for(int i=n-1;i>=0;i--){
            temp_sum += arr[i];
            answer_arr[i] = temp_sum;
        }
        for(int i=0;i<n;i++){
            cout<<answer_arr[i]<<" ";
        }cout<<endl;
    }
    return 0;
}