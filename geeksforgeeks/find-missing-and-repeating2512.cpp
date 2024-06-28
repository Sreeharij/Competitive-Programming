//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        long long summation_val = 0;
        long long squared_summation_val = 0;
        for(auto x: arr){
            summation_val += x;
            squared_summation_val += (long long)x*x;
        }
        
        long long expected_sum = (long long)n*(n + 1)/2;
        long long expected_squares = (long long)n*(n+1)*(2*n+1)/6;
        
        long long x_minus_y = expected_sum - summation_val;
        long long x_plus_y = (expected_squares - squared_summation_val) / x_minus_y;
        
        long long y = (x_plus_y - x_minus_y)/2;
        long long x = (x_plus_y + x_minus_y)/2;
        
        return {(int)y,(int)x};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends