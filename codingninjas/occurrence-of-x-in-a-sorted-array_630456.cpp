int get_last_idx(vector<int>& arr, int n, int x){
	int left = 0,right = n-1,mid;
	int required_idx=-1;
	while(left <= right){
		mid = (left + right) / 2;
		if(arr[mid] > x){
			right = mid - 1;
		}
		else{
			required_idx = mid;
			left = mid + 1;
		}
	}
	return required_idx;
}

int count(vector<int>& arr, int n, int x) {
	int occurance_end = get_last_idx(arr,n,x);
	int occurance_start = get_last_idx(arr,n,x-1);
	return occurance_end - occurance_start;
	
}
