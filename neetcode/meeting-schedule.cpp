/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */


class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int length = intervals.size();
        sort(intervals.begin(),intervals.end(),[](const Interval& x, const Interval& y){return x.start < y.start;});
        for(int i=0;i<length-1;i++){
            if(intervals[i].end > intervals[i+1].start){
                return false;
            }
        }
        return true;
    }
};
