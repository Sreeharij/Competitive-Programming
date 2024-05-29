int lowerBound(vector<int> arr, int n, int x) {
	int left = 0,right = n -1,mid;
	int required_idx = n;
	while(left <= right){
		mid = (left + right)/2;

		if(arr[mid] < x){
			left = mid + 1;
		}
		else{
			required_idx = mid;
			right = mid - 1;
		}
	}
	return required_idx;
}
