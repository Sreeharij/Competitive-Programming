// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        int low = 0,high=n;
        int mid;
        
        int answer = -1;
        
        while(low<=high){
            mid = (low+high)/2;
            if(v[mid]==x){
                return mid;
            }
            else if(v[mid] < x){
                answer = mid;
                low = mid + 1;
            }
            else{
                high = mid-1;
            }
        }
        return answer;
    }
};
