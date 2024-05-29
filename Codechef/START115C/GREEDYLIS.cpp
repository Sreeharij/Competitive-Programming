#include <bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void func(int n,int x){
    if(n == 2){
        if(x == 0){
            cout<<"1 2"<<endl;
        }
        else{
            cout<<-1<<endl;
        }
        return;
    }
    if(n == 1){
        if(x == 0){
            cout<<"1"<<endl;
        }
        else{
            cout<<-1<<endl;
        }
        return;
    }
    
    if(x > n-2){
        cout<<-1<<endl;
        return;
    }
    int answer[n];
    if(x == 0){
        for(int i=1;i<=n;i++){
            cout<<i<<" ";
        }cout<<endl;
        return;
    }
    else{
        int half = n - 2 - 1;
        answer[half] = n;
        for(int i=half+1;i<n;i++){
            answer[i] = i;
        }
        for(int i=1;i<=half;i++){
            answer[i-1] = i;
        }
        for(int j=1;j<x;j++){
            swap(&answer[half],&answer[half-1]);
            half = half-1;
        }
        
        for(int i=0;i<n;i++){
            cout<<answer[i]<<" ";
        }cout<<endl;
        return;
    }
}

int main() {
	int t,n,x;
	cin>>t;
	while(t--){
	    cin>>n>>x;
	    func(n,x);
	}
}