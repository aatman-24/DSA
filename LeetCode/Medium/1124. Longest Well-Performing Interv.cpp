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

Question: 1124. Longest Well-Performing Interval
Topic : prefixSum
Problems :  https://leetcode.com/problems/longest-well-performing-interval/

==============================> Explanation <=============================================
We starts with a score = 0,
If the working hour > 8, we plus 1 point.
Otherwise we minus 1 point.
We want find the maximum interval that have strict positive score.

After one day of work, if we find the total score > 0,
the whole interval has positive score,
so we set res = i + 1.

If the score is a new lowest score, we record the day by seen[cur] = i.
seen[score] means the first time we see the score is seen[score]th day.

We want a positive score, so we want to know the first occurrence of score - 1.
score - x also works, but it comes later than score - 1.
So the maximum interval is i - seen[score - 1]

==============================> Apporach and Time Complexity <=============================================
1) Prefix SUM:
Time: O(N)
Space: O(N) 
*/



class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int res = 0, score = 0, n = hours.size();
        unordered_map<int, int> seen;
        for (int i = 0; i < n; ++i) {
            score += hours[i] > 8 ? 1 : -1;

            // start from 0.
            if (score > 0) {
                res = i + 1;
            } else {
                if (seen.find(score) == seen.end())
                    seen[score] = i;
                
                if (seen.find(score - 1) != seen.end())
                    res = max(res, i - seen[score - 1]);
            }
        }
        return res;
    }
};