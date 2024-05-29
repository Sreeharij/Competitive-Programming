#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int t;
	cin>>t;
	while(t--){
	    int n,q;
	    cin>>n>>q;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    unordered_map<int,int> f;
	    multiset<int> left,right;
	    right.insert(arr[0]);
	    int right_sum = arr[0];
	    int left_sum = 0;
	    f[1] = right_sum - left_sum;
	    for(int k=3;k<=n;k+=2){
	        int smaller = min(arr[k-2],arr[k-1]);
	        int bigger = arr[k-2] + arr[k-1] - smaller;
	        left.insert(smaller);
	        right.insert(bigger);

	        int left_swap_val = *left.rbegin();
	        left.erase(next(left.rbegin()).base());
	        right.insert(left_swap_val);
	        
	        int right_swap_val = *right.begin();
	        right.erase(right.begin());
	        left.insert(right_swap_val);
	        
	        left_sum = left_sum + smaller - left_swap_val + right_swap_val;
	        right_sum = right_sum + bigger + left_swap_val - right_swap_val;

	        f[k] = right_sum - left_sum;
	    }
	    for(int i=0;i<q;i++){
	        int x;
	        cin>>x;
	        cout<<f[x]<<" ";
	    }cout<<endl;
	}
}