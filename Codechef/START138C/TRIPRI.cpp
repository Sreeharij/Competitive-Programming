#include <iostream>
#include <ios>
#include <limits>
#include <bits/stdc++.h>
using namespace std;


static const auto _______ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

void SieveOfEratosthenes(vector<long long>& primes) {
    int n = 100000;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            primes.push_back((long long)p * p);
        }
    }
}

int main() {
    vector<long long> primes;
    SieveOfEratosthenes(primes);

    int t;
    long long n;
    cin >> t;
    
    while(t--){
        cin>>n;
        bool found = false;
        int upper_limit = primes.size();
        for(int i=0;i<primes.size();i++){
            if(primes[i] >= n){
                upper_limit = i;
                break;
            }
        }
        
        for(int i=0;i<primes.size()-2;i++){
            if(found)break;
            int left = i+1;
            int right = upper_limit;
            while(left<right){
                long long current_sum = primes[i] + primes[left] + primes[right];
                if(current_sum == n){
                    found = true;
                    break;
                } 
                else if(current_sum > n){
                    right--;
                } 
                else{
                    left++;
                }
            }
        }
        if(found){
            cout<<"YES"<<endl;
        } 
        else{
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}
