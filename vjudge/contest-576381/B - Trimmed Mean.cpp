#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    double answer=0;
    int arr[5*n];
    for(int i=0;i<5*n;i++){
        cin>>arr[i];
    }
    sort(arr,arr + 5*n);
    for(int i=n;i<4*n;i++){
        answer += arr[i];
    }

    answer = answer/(3*n);
    cout<<answer<<endl;

    return 0;
}