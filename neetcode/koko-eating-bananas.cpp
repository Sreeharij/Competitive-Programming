class Solution {
public:
    bool check_feasibility(vector<int>& piles,long long h,long long k){
        long long hours_required = 0;

        for(int i=0;i<piles.size();i++){
            hours_required += piles[i]%k==0 ? piles[i]/k : piles[i]/k + 1;
        }
        return hours_required<=h;
    }

    int minEatingSpeed(vector<int>& piles, long long h) {
        long long answer = 0;
        long long lower_bound = 1;
        long long upper_bound = 0;
        long long mid;
        for(int i=0;i<piles.size();i++){
            upper_bound = piles[i] > upper_bound ? piles[i] : upper_bound;
        }

        while(lower_bound<=upper_bound){
            mid = (lower_bound + upper_bound)/2;

            if(check_feasibility(piles,h,mid)){
                answer = mid;
                upper_bound = mid - 1;
            }
            else{
                lower_bound = mid + 1;
            }
        }
        return answer;
    }
};