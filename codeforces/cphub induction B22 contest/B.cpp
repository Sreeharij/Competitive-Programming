#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    int first = a > b ? a : b;
    int second = a > b ? b : a;
    int temp;
    while (second) {
        temp = second;
        second = first%second;
        first = temp;
    }
    return first;
}

int func(int arr[],int size,bool* prime_flag){
    sort(arr,arr+size);
    int answer = 0;
    int gcd_val;
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            gcd_val = gcd(arr[i],arr[j]);
            if(prime_flag[gcd_val] == true){
                answer++;
            }
        }
    }
    return answer;
}


int main() {
    int t,n;
    bool *prime_flag = new bool[10000 + 1];
    for(int i =0;i<10000 + 1;i++){
        prime_flag[i] = true;
    }
    for(int i = 2;i*i<=10000 + 1;i++){
        if(prime_flag[i]){
            for(int j = i*i;j<=10000 + 1;j+=i){
                prime_flag[j] = false;
            }
        }
    }
    prime_flag[0] = prime_flag[1] = false;
    cin>>t;
    
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<func(arr,n,prime_flag)<<endl;
    } 
    return 0;
}