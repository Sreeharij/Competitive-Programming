#include <iostream>
using namespace std;

bool check_feasibility(int arr[],int n,int D,int equalised_value){
    for(int i=0;i<n;i++){
        if(!(arr[i] == equalised_value || (arr[i]+D) == equalised_value || (arr[i] - D) == equalised_value)){
            return false;
        }
    }
    return true;
}

int func(int arr[],int n){
    int answer = -1;
    int max_val = arr[0],min_val = arr[0];
    for(int i=0;i<n;i++){
        max_val = max_val > arr[i] ? max_val : arr[i];
        min_val = min_val < arr[i] ? min_val : arr[i];
    }
    if((max_val - min_val)%2==0){
        int D = (max_val-min_val)/2;
        int equalised_value = min_val + D;
        if(check_feasibility(arr,n,D,equalised_value)){
            answer = D;
        }
    }
    if(check_feasibility(arr,n,max_val - min_val,max_val) || check_feasibility(arr,n,max_val - min_val,min_val)){
        if(answer == -1){
            answer = max_val - min_val;
        }
        else{
            answer = answer < (max_val - min_val) ? answer : (max_val-min_val);
        }
    }
    return answer;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int result = func(arr,n);
    cout<<result<<endl;
    return 0;
}