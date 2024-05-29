//Optimised solution using mathematical approach for counting subsequence
string moreSubsequence(int n, int m, string a, string b)
{
    unordered_map<char,int> freq_map1,freq_map2;
    int count1=1,count2=1;
    for(int i=0;i<n;i++){
        freq_map1[a[i]]++;
    }
    for(int j=0;j<m;j++){
        freq_map2[b[j]]++;
    }
    for(auto x:freq_map1){
        count1 *= (x.second + 1);
    }count1--;
    for(auto x:freq_map2){
        count2 *= (x.second + 1);
    }count2--;
    if(count2 > count1){
        return b;
    }
    return a;    
}