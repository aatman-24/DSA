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

Question: 1109. Corporate Flight Bookings
Topic : prefixSum, Sweep Line
Problems :  https://leetcode.com/problems/corporate-flight-bookings/

==============================> Explanation <=============================================

Parent Problem: 1589. Maximum Sum Obtained of Any Permutation


- Ideas is clear that,

1) Brute Force: (TLE)
- Simple, make count[n] = {0},
-for every request add the freq of customer in the count of the index from start -> end.

2) Prefix Array(Sweep Line):

How ???

1) Imagine that you had intervals [1:3], [3:5].

2) For each mark boundaries only to avoid complexity raise (TLE) on a wide interval as you 
do nothing with values inside the interval and ignore it quantity.

(here instead of 1 we use custmoer freq)

t[start] += 1 means every index after this one will be counted 1 more time, 
t[end+1] -= 1, means every index this one will be counted 1 less time

after [1:3] : [0, 1(+1), 0, 0, -1(-1), 0, 0]

after [3:5] : [0, 1, 0, 1(+1), -1, 0, -1(-1)]

3)Then after all intervals start|end+1 marking we can set the final frequency in one pass.
So the prefix sum of t will correspond to the number of requests for each index.

for i in range(1, n):
    count[i] += count[i - 1]

It will become
[0, 1, 0, 1, -1, 0, -1] -> [0, 1, 1, 2, 1, 1, 0]

In short, 

[start: end] -> freq[start]++, freq[end+1]--;

                After performing prefix sum give,  freq[start] -> freq[end] is added by one. And after freq[end] again will
                be the same due to freq[end+1]--. (1 - 1) = 0.

This trick is called Sweep Line.




==============================> Apporach and Time Complexity <=============================================
1) Brute Force:
Time: O(N^2) -> TLE here, N = 10^5.
Space: O(N) 

2) Prefix Sum Construction(Sweep Line):
Time:O(N)
Space:O(N)

*/


class Solution {
public:

    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {

        vector<int> count(n, 0);

        for(auto it: bookings) {

            // 0th index
            int start = it[0] - 1, end = it[1] - 1, freq = it[2];

            // sweep line.
            count[start] += freq;
            if(end + 1 < n) count[end+1] -= freq;
        }


        // prefix sum.
        for(int i = 1; i < n; i++) {
            count[i] += count[i-1];
        }


        return count;
    }
};