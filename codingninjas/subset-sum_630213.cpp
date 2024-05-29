bool backtrack(vector<int> &a,int target,int start){
    if(target == 0){
        return true;
    }
    for(int i=start;i<a.size();i++){
        if(a[i] > target) return false;
        if(backtrack(a,target-a[i],i+1)){
            return true;
        }
    }
    return false;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    sort(a.begin(),a.end());
    return backtrack(a,k,0);
}