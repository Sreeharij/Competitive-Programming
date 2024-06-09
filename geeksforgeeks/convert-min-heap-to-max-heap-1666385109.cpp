//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void heapify(vector<int>& arr,int i,int n){
        int left_child,right_child,largest;
        while(true){
            left_child = 2*i+1;
            right_child = 2*i+2;
            largest = i;
            if(left_child < n && arr[left_child] > arr[largest]){
                largest = left_child;
            }
            if(right_child < n && arr[right_child] > arr[largest]){
                largest = right_child;
            }
            if(largest == i)return;
            swap(arr[i],arr[largest]);
            i = largest;
        }
    }
    
    void convertMinToMaxHeap(vector<int> &arr, int N){
        int starting_idx = N/2-1;
        for(int i=starting_idx;i>=0;i--){
            heapify(arr,i,N);
        }
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends