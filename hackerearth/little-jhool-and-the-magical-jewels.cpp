#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int t;
    cin>>t;
	string s;
	while(t--){
		int arr[4] = {0};
        cin>>s;
		int length = s.size();
        for(int i=0;i<length;i++){
            if(s[i]=='r'){
                arr[0]++;
            }
            else if(s[i]=='u'){
                arr[1]++;
            }
            else if(s[i]=='b'){
                arr[2]++;
            }
            else if(s[i]=='y'){
                arr[3]++;
            }
        }
        cout<<*min_element(arr,arr+4)<<endl;
	}

	return 0;
}