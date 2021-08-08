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
d
/*
==============================> Description <=============================================

Question : 452. Minimum Number of Arrows to Burst Balloons
Topic : Greedy
Problems : https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
/*
==============================> Explanation <=============================================

- Overlapping Interval Problem. Here Need to count total Non-overlapping Interval. But once the 
end_time is fixed not change with next acitivty end_time. If acitivity start before the end mark as
overlap don't need to update end_time with this activity.


Why ?

- Here we need to select point x such that Xbegin <= x <= Xend.  So we select the point acitivity end_time.
So this points one we selected we can not change it. If we change it then we need one more arrow here.


And why sorting is based on acitivity which ends first rathar than start first ?

- Because If we take the acitivity with the start first then its end time may not relevent with acitivity start 
time.  

Sorting based on start_time:

        [3,9] [9,10] [6,8] [7,12] output = 1. Excepted = 2.

end_time = 9.     take [6,8] which not cover x = 9. But it is marked as overlapping inteval due to end_time > 6.
Which is wrong. 


Sorting based on end_time:

        [6,8] [3,9] [9,10] [7,12] output = 2. Excepted = 2. (first two and last two)


- Here we got the point x = 8, which is coverd into first two. and same for last two.

Why greedy works ?

- Once we sort the acitivity on end_time. Then any acitivity whose start_time is coverd into this is shooted by
the first_acitivity end points. And we can skip all overlapping interval.


56 Merge Intervals <- very similar😈
435 Non-overlapping Intervals <- very similar😈
252 Meeting Rooms
253 Meeting Rooms II


*/


/*
==============================> Edge Case <=============================================


*/


class Solution {
public:

    int findMinArrowShots(vector<vector<int>>& points) {
            

        // points whose end first which should be first. If same then begin of point be less. 
        sort(points.begin(), points.end(), [](vector<int> p1, vector<int> p2) {
            if(p1[1] == p2[1]) p1[0] < p2[0];
            return p1[1] < p2[1];
        });

        int count = 1;
        int end_time = points[0][1];

        for(int i = 1; i < points.size(); i++) {

            // If points begin points greater then current the need one more arrow.
            if(points[i][0] > end_time) {
                count++;
                end_time = points[i][1];
            }

        }


        return count;

    } 
};  