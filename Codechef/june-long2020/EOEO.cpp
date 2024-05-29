#include <iostream>
#include <cmath>
using namespace std;
long long int Testcases;
long long int i;
long long int highesttwo;
long long int Cat;
long long int result;
int main() {
    cin>>Testcases;
    for(i=0;i<Testcases;i++)
    {
        cin>>Cat;
        if (Cat%2!=0){
            result = (Cat/2);
        }
        else if (Cat%2==0){
            highesttwo = (Cat & (~(Cat-1)));
            result = Cat/(2*highesttwo);
        }
        cout<<result<<endl;
    }
    return 0;
}
