//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n){
        unordered_map<int,int> mp;
        int old_number = 0;
        int max_size = 0;
        mp[0] = -1;
        for(int i=0;i<n;i++){
            old_number += A[i];
            if(mp.count(old_number)){
                max_size = max(max_size,i - mp[old_number]);
            }
            else{
                mp[old_number] = i;
            }
        }
        return max_size;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends