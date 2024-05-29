int findKRotation(vector<int> &arr){
    int left = 0;
    int right = arr.size() -1 ;
    int answer=0;

    if(arr.size() == 1) return 0;
    if(arr[0] > arr[1]) return 1;
    if(arr[arr.size()-1] < arr[arr.size() -2 ]) return arr.size()-1;
    
    left += 1;
    right -= 1;

    while(left < right){
        int mid = (left + right)/2;
        if(arr[left] <= arr[mid]){
            if(arr[mid] > arr[mid+1]){
                answer = mid+1;
                break;
            }
            left = mid + 1;
        }
        else{
            if(arr[mid] < arr[mid-1]){
                answer = mid;
                break;
            }
            right = mid - 1;
        }
    }
    return answer;
}