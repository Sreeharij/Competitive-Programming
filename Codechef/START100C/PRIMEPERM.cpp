#include <iostream>
using namespace std;

void func(int n){
    if(n<=3){
        cout<<-1<<endl;
    }
    else if(n%4 == 0){
        int k = n/4;
        for(int i=1;i<=k;i++){
            cout<<4*i-1<<" "<<4*i<<" "<<4*i-3<<" "<<4*i-2<<" ";
        }cout<<endl;
    }
    else if(n%4 == 1){
        cout<<"4 5 1 2 3 ";
        for(int i=9;i<=n;i=i+4){
            cout<<i-1<<" "<<i<<" "<<i-3<<" "<<i-2<<" ";
        }cout<<endl;
    }
    else if(n%4 == 2){
        cout<<"4 5 6 1 2 3 ";
        for(int i=10;i<=n;i=i+4){
            cout<<i-1<<" "<<i<<" "<<i-3<<" "<<i-2<<" ";
        }cout<<endl;
    }
    else if(n%4 == 3){
        cout<<"3 4 5 6 7 1 2 ";
        for(int i=11;i<=n;i=i+4){
            cout<<i-1<<" "<<i<<" "<<i-3<<" "<<i-2<<" ";
        }cout<<endl;
    }
    
}

int main() {
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    func(n);
	}
	return 0;
}
