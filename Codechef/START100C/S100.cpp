#include <iostream>
using namespace std;

int main() {
	int t,n;
	cin>>t;
	bool flag;
	while(t--){
	    cin>>n;
	    flag = false;
	    char arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int i=0;
	    for(i=0;i<n-2;i++){
	        if(arr[i] == '1'){
	            cout<<'1';
	            i = i+1;
	            flag = true;
	            break;
	        }
	        else{
	            cout<<'0';
	        }
	    }
	    for(int j=i;j<n;j++){
	        if(flag){
	            cout<<'0';    
	        }
	        else{
	            cout<<arr[j];
	        }
	    }cout<<endl;
	}
	return 0;
}
