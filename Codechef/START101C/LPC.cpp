#include <iostream>
#include <climits>
using namespace std;

int func(char S[], char K[], int n,int m){
    int min_moves = INT_MAX;
    for(int i=0;i<n-m+1;i++){
        int diff;
        int current_moves = 0;
        for(int j=0;j<m;j++){
            diff = abs(S[i+j] - K[j]);
            diff = min(diff,10-diff);
            current_moves += diff;
        }
        min_moves = min(min_moves,current_moves);
    }
    return min_moves;
}

int main() {
	int t,n,m;
	cin>>t;
	while(t--){
	    cin>>n>>m;
	    char S[n];
	    char K[m];
	    for(int i=0;i<n;i++){
	        cin>>S[i];
	    }
	    for(int i=0;i<m;i++){
	        cin>>K[i];
	    }
	    cout<<func(S,K,n,m)<<endl;
	}
	return 0;
}