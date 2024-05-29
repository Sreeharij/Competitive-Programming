#include <iostream>
using namespace std;

int main(){
    int n,m,a;
    cin>>n>>m>>a;
    long long length = n%a==0 ? n/a : n/a + 1;
    long long breadth = m%a==0 ? m/a : m/a + 1;
    cout<<length * breadth<<endl;

    return 0;
}