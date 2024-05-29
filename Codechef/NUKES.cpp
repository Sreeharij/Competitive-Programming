#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    long long int A,original,N,K,i;
    cin>>A>>N>>K;
    long long int arr[K+1] = {0};
    arr[0] = A;
    for(i=1;i<K+1;i++){
        original = arr[i-1];
        arr[i-1] = arr[i-1]%(N+1);
        arr[i] = original/(N+1);
    }
    for(i=0;i<K;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

