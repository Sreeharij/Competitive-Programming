#include <bits/stdc++.h>
using namespace std;

int directions[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int main() {
	int t;
	cin>>t;
	while(t--){
	    int r,c,k;
	    cin>>r>>c>>k;
	    int count = 0;
	    r--;
	    c--;
	    for(int i=0;i<8;i++){
	        for(int j=0;j<8;j++){
	            if(max(abs(i-r),abs(j-c)) <= k){
	                count++;
	            }
	        }
	    }
	    cout<<count<<endl;
	}
}
