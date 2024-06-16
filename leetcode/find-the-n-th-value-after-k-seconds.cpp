class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        int MOD = 1e9+7;
        vector<int> array(n,1);
        while(k--){
            for(int i=1;i<n;i++){
                array[i] =(array[i]%MOD + array[i-1]%MOD)%MOD;
            }
        }
        return array[n-1];
    }
};