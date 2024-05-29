#include <bits/stdc++.h>
using namespace std;

void func(int A[],int B[],int n){
    int summation = A[0] + B[0];
    for(int i=1;i<n;i++){
        if(A[i] + B[i] != summation){
            cout<<-1<<endl;
            return;
        }
    }
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }cout<<endl;
    for(int i=0;i<n;i++){
        cout<<B[i]<<" ";
    }cout<<endl;
    return;
}

int main() {
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int A[n],B[n];
	    for(int i=0;i<n;i++){
	        cin>>A[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>B[i];
	    }
	    sort(A,A+n);
	    sort(B,B+n,greater<int>());
	    func(A,B,n);
	}

}