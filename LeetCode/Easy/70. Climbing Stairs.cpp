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

Question: 70. Climbing Stairs
Topic : DP, Pattern=Fibonacci
Problems : https://leetcode.com/problems/climbing-stairs/

==============================> Explanation <=============================================

=>> Choice Diagram -> Given N -> We can jump to (N-1) or (N-2).
Explanation: Here We go from N -> 0. If we reach to the 0 that means our path is valid. We can jump from N to
N-1 or N-2.

==> Base Case -> N == 0 Return 1.
              -> N < 0  Return 0.
Explanation: If we at 0th stair then we don't need to go anywhere means we reached at the target return 1. For
             the negative number we return 0.


==> Recurrance Relation:
    Count(N) = Count(N-1) + Count(N-2).

Explanation: Number of Ways to reach (N -> 0) is number of ways (N-1 -> 0) + (N-2 -> 0). Here we find the
             number of ways so we have to plus all the answer inplace of OR.


==============================> Apporach and Time Complexity <=============================================
1) DP, Pattern=Fibonacci:
Time: O(N) (Because There are total N calls be made) * (In Each call O(1) work done) -> O(N)
Space: O(1) O(N)(Memorization)

*/


// Top-Down Approach:
class Solution {
public:
    
    // memo table.
    int t[46];

    int numberOfWay(int n) {
                
        // Number of Ways is zero.
        if(n <= 0)
            return 0;

        // one way (1 -> 0)
        if(n == 1)
            return 1;

        // two way (2 -> 0) (2 -> 1 -> 0)
        if(n == 2)
            return 2;

        // Already Solved this Subproblem. 
        if(t[n] != -1)
            return t[n];

        // For the current N, we declare the totalWays as 0.
        int totalWays = 0;
       
        // Don't jump at negative number(staircase).
        if(n - 1 >= 0) {

            // if subproblem is not solved then first solve it.
            if(t[n-1] == -1)
                t[n-1] = numberOfWay(n-1);
            totalWays += t[n-1];
        }
        
        if(n - 2 >= 0) {
            if(t[n-2] == -1)
                t[n-2] = numberOfWay(n-2);
            totalWays += t[n-2];
        }
    

        // memoriaze and return it.
        return t[n] = totalWays;
    }


    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
        return numberOfWay(n);
    }
};


// Top-Down 
class Solution {
public:
    
   int climbStairs(int n) {

        int dp[n+1];
        memset(dp, 0, sizeof(dp));

        // Base case
        // N == 1 one way to reach 0. (1 -> 0).
        dp[1] = 1;

        // N = 2 two way to reach 0. (2 -> 0) and (2 -> 1 -> 0).
        dp[2] = 2;

        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};