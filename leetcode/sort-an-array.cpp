//Sorting an array using merge sort
class Solution {
public:
    void merge(vector<int>& nums,vector<int>& left_arr,vector<int>& right_arr,int left,int mid,int right){
        int left_size = mid - left + 1;
        int right_size = right - mid;
        for(int i=0;i<left_size;i++){
            left_arr[i] = nums[left + i]; 
        }
        for(int i=0;i<right_size;i++){
            right_arr[i] = nums[mid+1+i];
        }
        int i=0,j=0,k=left;
        while(i < left_size && j < right_size){
            if(left_arr[i] <= right_arr[j]){
                nums[k++] = left_arr[i++];
            }   
            else{
                nums[k++] = right_arr[j++];
            }
        }
        while(i < left_size){
            nums[k++] = left_arr[i++];
        }
        while(j < right_size){
            nums[k++] = right_arr[j++];
        }
    }

    void mergeSort(vector<int>& nums,vector<int>& left_arr,vector<int>& right_arr,int left,int right){
        if(left < right){
            int mid = (left + right)/2;
            mergeSort(nums,left_arr,right_arr,left,mid);
            mergeSort(nums,left_arr,right_arr,mid+1,right);
            merge(nums,left_arr,right_arr,left,mid,right);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_arr(n,0);
        vector<int> right_arr(n,0);
        mergeSort(nums,left_arr,right_arr,0,n-1);

        return nums;
    }
};

//Sorting an array using heapsort
class Solution {
public:
    void swap(int& a,int& b){
        int temp = a;
        a = b;
        b = temp;
    }

    void heapify(vector<int>& nums,int i,int n){
        int left_child,right_child,largest;
        while(true){
            left_child = 2*i+1;
            right_child = 2*i+2;
            largest = i;
            if(left_child < n && nums[left_child] > nums[largest]){
                largest = left_child;
            }
            if(right_child < n && nums[right_child] > nums[largest]){
                largest = right_child;
            }
            if(i == largest)return;
            swap(nums[i],nums[largest]);
            i = largest;
        }
    }

    void build_max_heap(vector<int>& nums,int n){
        int start_idx = n/2-1;
        for(int i=start_idx;i>=0;i--){
            heapify(nums,i,n);
        }
    }

    void heapsort(vector<int>& nums,int n){
        build_max_heap(nums,n);

        for(int i=n-1;i>0;i--){
            swap(nums[0],nums[i]);
            heapify(nums,0,i);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        heapsort(nums,nums.size());
        return nums;
    }
};