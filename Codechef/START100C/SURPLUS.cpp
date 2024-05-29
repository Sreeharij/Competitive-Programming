#include <iostream>
using namespace std;

int main() {
	int t,a1,a2,b1,b2;
	cin>>t;
	while(t--){
	   cin>>a1>>a2>>b1>>b2;
	   if(-(a1 + b1 - a2 - b2) > 0){
	       cout<<"YES"<<endl;
	   }
	   else{
	       cout<<"NO"<<endl;
	   }
	}
	return 0;
}
