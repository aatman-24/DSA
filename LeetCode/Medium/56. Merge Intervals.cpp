#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007
#define eps 1e-6

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

Question : 56. Merge Intervals
Topic : Greedy Pattern=Interval
Problems : https://leetcode.com/problems/merge-intervals/

==============================> Explanation <=============================================

- Greedy Approach, Standard pattern = Intervals.

- We first sort all the intervals based on first_start, first_Finish.
- We keep track of start and end point of interval. Initialize with first interval...
- If found the interval which is start after the current end points. end < interval[i][0].
    Then we add current {start, end} into the result. 
    Update start and end with that interval.
- If interval is overlapped... then we just update the end point with max(end, interval[i][1]).

==============================> Apporach and Time Complexity <=============================================

1) Greedy-Intervals
Time: O(NlogN)
Space: O(1)

*/

class Solution {

public:

    // First_start, first_finish
   static bool sort_fun(vector<int> a, vector<int> b) {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), sort_fun);

        vector<vector<int>> ans;
        int start = intervals[0][0], end = intervals[0][1]; 
        for(int i = 1; i < intervals.size(); i++) {

            // [non-overlap] add current {start, end} into the answer. and update 
            // new start and end.
            if(intervals[i][0] > end) {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }

            // [overlap] update the end point.
            else {
                end = max(end, intervals[i][1]);
            }
        }
        ans.push_back({start,end});

        return ans;

    }

};