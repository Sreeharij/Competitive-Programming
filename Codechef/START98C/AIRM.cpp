#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        int arrival[n];
        int departure[n];
        map <int,int> freq_arr;
        for(int i=0;i<n;i++){
            cin>>arrival[i];
        }
        for(int i=0;i<n;i++){
            cin>>departure[i];
        }
        for(int i=0;i<n;i++){
            freq_arr[arrival[i]]++;
            freq_arr[departure[i]]++;
        }
        int max_val = INT_MIN;
        for(auto x:freq_arr){
            max_val = x.second > max_val ? x.second : max_val;
        }
        cout<<max_val<<endl;
    }
	return 0;
}