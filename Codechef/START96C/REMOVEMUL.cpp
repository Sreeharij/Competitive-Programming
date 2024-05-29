#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    long long int n,m;
    while(t--){
        cin>>n>>m;
        long long int Q_arr[m];
        long long int sum = 0;
        for(long long int i=0;i<m;i++){
            cin>>Q_arr[i];
            sum += Q_arr[i];
        }
        long long int max_sum = n*(n+1)/2;
        long long int ans = max_sum - sum;
        cout<<ans<<endl;
    }
    return 0;
}