#include <bits/stdc++.h>
using namespace std;

void func(long long int n){
    long long int upper_bound = sqrt(n);
    bool flag = true;
    long long int arr[3] = {-1,-1,-1};
    int counter = 0;
    int arr_idx_counter = 0;
    long long int i;
    for(i = 2;i<=upper_bound;i++){
        if(counter==2){
            break;
        }
        if(n%i==0){
            flag = false;
            arr[arr_idx_counter++] = i;
            n = n/i;
            counter++;
        }
    }
    i--;
    if(counter==2){
        if(n>i){
            arr[2] = n;
            cout<<"YES"<<endl;
            cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
        }
        else{
            flag = true;
            cout<<"NO"<<endl;
        }
    }
    else{
        flag = true;
        cout<<"NO"<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    long long int n;
    while(t--){
        cin>>n;        
        func(n);
        
    }
    return 0;
}