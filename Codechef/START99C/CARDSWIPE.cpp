#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        int absolute_max = 0;
        int current_max = 0;
        unordered_map<int,int> freq;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            if(freq[arr[i]] == 1){
                freq[arr[i]] = 0;
                current_max -= 1;
            }
            else{
                current_max += 1;
                freq[arr[i]] = 1;
            }
            absolute_max = current_max > absolute_max ? current_max : absolute_max;
        }
        cout<<absolute_max<<endl;

    }
    return 0;
}