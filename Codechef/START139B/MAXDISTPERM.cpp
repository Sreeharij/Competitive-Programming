#include <bits/stdc++.h>
using namespace std;

void func(int n){
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i=n/2+1;i<=n;i++){
        cout<<i<<" ";
    }
    for(int i=1;i<=n/2;i++){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main() {
	int t;
	cin>>t;
	int n;
	for(int i=0;i<t;i++){
	    cin>>n;
	    func(n);
	}
	
	
	return 0;
}
