#include <iostream>
using namespace std;

int main() {
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    if(n%2==0){
	        cout<<1<<" "<<1<<" "<<n-2<<endl;
	    }
	    else{
	        cout<<1<<" "<<(n-1)/2<<" "<<(n-1)/2<<endl;
	    }
	}
	return 0;
}
