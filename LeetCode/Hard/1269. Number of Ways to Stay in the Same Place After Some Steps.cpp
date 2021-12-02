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

Question: 1269. Number of Ways to Stay in the Same Place After Some Steps
Topic : Top-Down Bottom-up Pattern=MultiDimensionalDP
Problems : https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/

==============================> Explanation <=============================================
- Dp variant = MultiDimensionalDP.

After saw the problem first idea comes into the mind is MultiDimensionalDP.... very straightforward solution..


Problem is in Hard category because,

steps = 500, arrLen = 10^6.

- But logic is simple, if we are allowed to take one step left or right.. then we can go farthest upto 500
not more than that..... 

So dp[501][501] is memo/dp table not..... dp[501][10^6+1]....


1) Choise Diagram: 

If we are now taking the nth step and want to reach at the cur position...

dp[n][cur] = dp[n-1][cur-1] or dp[n-1][cur] or dp[n-1][cur+1]

Then we can jump from the (n-1)step and (cur-1, cur, cur+1]) positions.


2) Base Case: dp[0][0] = 1. (taking 0th step and 0th pos) which is our destination.
              
3) Recurrance Relation:
                
        dp[n][cur] = dp[n-1][cur-1] + dp[n-1][cur] + dp[n-1][cur+1].


Already knew in the MultiDimensionalDP we can Reduce the space in one level below.

Here, I directly implement O(N) solution without taking O(N^2) which is same as top-down.

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern=MultiDimensionalDP
Time: O(N^2)
Space: O(N^2)

2) Memory Optimization:
Time:O(N^2)
Space:O(N)

*/


#define mod 1000000007

class Solution {
public:
   
    long t[501][501];

    long numWays(int cur, int n, int farthest) {

        if(n == 0)
            return (long) cur == 0;

        if(cur < 0 || cur >= farthest)
            return 0;

        if(t[n][cur] != -1)
            return t[n][cur];

        long count = 0;

        count = numWays(cur-1, n-1, farthest) % mod +
                numWays(cur, n-1, farthest) % mod +
                numWays(cur+1, n-1, farthest) % mod;

        return t[n][cur] = count % mod;
    }


    int numWays(int n, int len) {

        for(int i = 0; i < 501; i++) {
            for(int j = 0; j < 501; j++) {
                t[i][j] = -1;
            }
        }

        int farthest = min(n, len);

        return (int)numWays(0, n, farthest);
    }
};




#define mod 1000000007

class Solution {
public:

    int numWays(int steps, int arrLen) {

        int farthest = min(steps, arrLen);

        vector<long> dp(farthest+1, 0), t(farthest+1, 0);
        dp[0] = 1;

        for(int i = 1; i <= steps; i++) {

            for(int j = 0; j < farthest; j++) {             // steps and arrLen is consider as 1 based index.
            
                t[j] = dp[j] % mod;
                if(j - 1 >= 0) t[j] += (dp[j-1] % mod);
                if(j + 1 < n)  t[j] += (dp[j+1] % mod);
            
            }

            swap(dp, t);
        }
        
        return dp[0] % mod;
    }
};