#include <iostream>
using namespace std;

bool check_feasibility(int arr[],int n,int h,int k){
    for(int i=0;i<n;i++){
        if(arr[i] > k){
            if(h < arr[i] ){
                return false;
            }
            h = h - arr[i];
        }
    }    
    if(h > 0){
        return true;
    }
    return false;
}

int func(int arr[],int n,int h){
    
    int upper_bound = arr[0];
    for(int i=1;i<n;i++){
        upper_bound = max(upper_bound,arr[i]);
    }
    int lower_bound = 0;
    int answer = upper_bound;
    while(lower_bound <= upper_bound){
        int mid = (lower_bound + upper_bound)/2;
        if(check_feasibility(arr,n,h,mid)){
            answer = mid;
            upper_bound = mid - 1;
        }
        else{
            lower_bound = mid + 1;
        }
    }
    return answer;
}

int main() {
	int t,n,h;
	cin>>t;
	while(t--){
	    cin>>n>>h;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cout<<func(arr,n,h)<<endl;
	}
	return 0;
}