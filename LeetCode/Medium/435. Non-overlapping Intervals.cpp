#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

using namespace std;


typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef map<int,int> mii;

/*
==============================> Description <=============================================

Question : 435. Non-overlapping Intervals
Topic : Scheduling, Greedy
Problems : https://leetcode.com/problems/non-overlapping-intervals/

/*
==============================> Explanation <=============================================
Standard Scheduling problem:

1) first two algorithm which is same
- sort interval first start_time and then end_time.
- after than if interval start_time < cur_end_time -> overlap -> update the cur_end time minimum of them.
start_time > cur_end_time  -> nonoverlap -> cur_end_time = interval.end_time.

What I study into college.
3) Sort the activity(interval) whose end first.
- sort interval ending time and if ending time equal then starting time.
- after doing this when the start_time >= cur_end_time -> non_overlap -> update the cur_end_time.
- Otherwise just increase the index all non_overalap automatically discard no need to update the cur_end_time
because it is already minimum due to sort.

*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // sort intervals a.start < b.start and a.start == b.start && a.end < b.end
        sort(intervals.begin(),intervals.end());

        // count maximum non_overlap
        int end_time = intervals[0][1], non_overlap = 1;
        int index = 1;
        while(index < n) {
            if(!(intervals[index][0] < end_time)) {
                end_time = intervals[index][1];
                non_overlap++;
            }
            else {
                end_time = min(end_time, intervals[index][1]);  // delete interval whose end_time is big.
                // end_time = 5 [1 5] [2 4] we choose [2,4] rather than [1,5].
            }
            index++;
        }

        // minimum_overlap = n - maximum_non_overlap
        return n - non_overlap;
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();
        sort(intervals.begin(),intervals.end());

        int end_time = intervals[0][1], overlap = 0;
        int index = 1;
        while(index < n) {
            if(!(intervals[index][0] < end_time)) {
                end_time = intervals[index][1];             // update end time. 
            }
            else {
                end_time = min(end_time, intervals[index][1]);  // delete interval whose end_time is big.
                overlap++;
            }
            index++;
        }

        return overlap;
     }


     int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // sort intervals a.start < b.start and a.start == b.start && a.end < b.end
        sort(intervals.begin(),intervals.end(), [](const vector<int> v1, const vector<int> v2) {
            if(v1[1] == v2[1]) return v1[0] < v2[0];
            return v1[1] < v2[1];
        });

        // count maximum non_overlap
        int end_time = intervals[0][1], non_overlap = 1;
        int index = 1;
        while(index < n) {
            if(intervals[index][0] >= end_time) {
                end_time = intervals[index][1];
                non_overlap++;
            }
            index++;        // no need to end_time = min(end_time, intervals[index][1]); already sorted that way.
        }

        // minimum_overlap = n - maximum_non_overlap
        return n - non_overlap;
    }

};