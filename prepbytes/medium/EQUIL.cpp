#include <iostream>

using namespace std;

int main()
{
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int max_length = 100001;
        int counting_arr[max_length] = {0};
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            counting_arr[arr[i]] += 1;
        }
        int idx=0;
        for(int i=0;i<max_length;i++){
            int number_frequency = counting_arr[i];
            for(int j=0;j<number_frequency;j++){
                arr[idx] = i;
                idx++;
            }
        }
        int counter=0;
        for(int i=n-1;i>=0;i--){
            if((counter+1)<=arr[i]){
                counter++;
            }
        }
        cout<<counter<<endl;
        
        
    }

    return 0;
}