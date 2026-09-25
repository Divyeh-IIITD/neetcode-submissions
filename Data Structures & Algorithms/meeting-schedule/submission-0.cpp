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

    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(),
             [](const Interval& a, const Interval& b) {
                 return a.end < b.end;
             });

        int ans = 0;
        int end = intervals[0].end;

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < end) {
                ans++;
            } else {
                end = intervals[i].end;
            }
        }

        return ans;
    }

    bool canAttendMeetings(vector<Interval>& intervals) {
        int j = eraseOverlapIntervals(intervals);
        if(j==0){
            return true;
        }
        return false;
    }
};