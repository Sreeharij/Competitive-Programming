//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
    private:
        bool static comp(Item first,Item second){
            return (double)first.value/(double)first.weight > (double)second.value/(double)second.weight;
        }
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        sort(arr,arr + n,comp);
        double answer = 0;
        
        for(int i=0;i<n;i++){
            if(arr[i].weight <= w){
                w -= arr[i].weight;
                answer += arr[i].value;
            }
            else{
                answer += (double)arr[i].value/arr[i].weight*w;
                break;
            }
        }
        return answer;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends