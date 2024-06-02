#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int answer = n;
	    int left = 0;
	    int right = 1;
	    while(right < n){
	        if(arr[right] < arr[right-1]){
	            answer += (right-left)*(right-left-1)/2;
	            left = right;
	            right++;
	        }
	        else{
	            right++;
	        }
	    }
	    answer += (right-left)*(right-left-1)/2;
        cout<<answer<<endl;
	}
}
