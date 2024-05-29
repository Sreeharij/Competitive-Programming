#include <bits/stdc++.h>
using namespace std;
int minPower(vector<int> cells){
    multiset<int> next_set;
    multiset<int> 
    current_set(cells.begin(),cells.end());
    int cost = 0;
    while(current_set.size() != 1){
        int current_set_length = current_set.size();
        for(int i=0;i<current_set_length;i+=2){
            if(i == current_set_length-1){
                auto it = current_set.begin();
                int val = *it;
                next_set.insert(val);
                
            }
            else{
                auto it = current_set.begin();
                int first = *it;
                current_set.erase(it);
                it = current_set.begin();
                int second = *it;
                current_set.erase(it);
                next_set.insert(first + second);
                cost += first+second;
            }
        }
        current_set = next_set;
        next_set.clear();
    }
    return cost;
}

int main(){
    vector<int> cells = {1,1,1,1,1};
    // for(int i=1;i<=5;i++){
    //     cells.push_back(i);
    // }
    cout<<minPower(cells)<<endl;
}