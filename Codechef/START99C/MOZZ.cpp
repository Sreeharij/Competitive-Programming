#include <iostream>
using namespace std;

int main() {
	int t,x,y,r;
	cin>>t;
	int extra;
	while(t--){
	    cin>>x>>y>>r;
	    extra = r/30;
	    if((x + extra)%y==0){
	        cout<<(x+extra)/y<<endl;
	    }
	    else{
	        cout<<(x+extra)/y + 1<<endl;
	    }
	    
	}
	return 0;
}
