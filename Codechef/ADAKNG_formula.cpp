#include <bits/stdc++.h>
using namespace std;

int directions[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int main() {
	int t;
	cin>>t;
	while(t--){
	    int r,c,k;
	    cin>>r>>c>>k;
	    cout<<(min(c+k,8) - max(c-k,1) + 1)*(min(r+k,8) - max(r-k,1) + 1)<<endl;
	}
}
