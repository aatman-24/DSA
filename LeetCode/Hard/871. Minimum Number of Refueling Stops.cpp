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

Question: 871. Minimum Number of Refueling Stops
Topic : Top-Down Bottom-up Pattern=LIS
Problems : https://leetcode.com/problems/minimum-number-of-refueling-stops/

==============================> Explanation <=============================================
- Dp variant = LIS.


1) Choise Diagram: 
dp[t] means the furthest distance that we can get with t times of refueling.

So for every station s[i],
if the current distance dp[t] >= s[i][0], we can refuel:
dp[t + 1] = max(dp[t + 1], dp[t] + s[i][1])

In the end, we'll return the first t with dp[t] >= target,
otherwise we'll return -1.


2) Base Case: dp[501] = {startFuel}. Fill all the t with given fuel.
              
3) Recurrance Relation:
                
        dp[t + 1] = max(dp[t + 1], dp[t] + s[i][1])


2) Using maxHeap:

- Same logic is used, level(tank used) time.

==============================> Apporach and Time Complexity <=============================================

1) Bottom-up Pattern=LIS
Time: O(N^2)
Space: O(N)

2) MaxHeap Greedy:
Time:O(NlogN)
Space:O(N)

*/


class Solution {
public:

    int minRefuelStops(int target, int startFuel, vector<vector<int>>& s) {

        long dp[501] = {startFuel};

        for(int i = 0; i < s.size(); i++) {
            for(int t = i; t >= 0 && dp[t] >= s[i][0]; t--) {
                dp[t+1] = max(dp[t+1], dp[t] + s[i][1]);
            }
        }

        for(int t = 0; t <= s.size(); t++) {
            if(dp[t] >= target)
                return t;
        }

        return -1;
    }
};


class Solution {
public:
    int minRefuelStops(int target, int cur, vector<vector<int>> s) {
        int i = 0, res;
        priority_queue<int>pq;

        for (res = 0; cur < target; res++) {
            while (i < s.size() && s[i][0] <= cur)
                pq.push(s[i++][1]);
            if (pq.empty()) return -1;
            cur += pq.top(), pq.pop();
        }
        return res;
    }
};
