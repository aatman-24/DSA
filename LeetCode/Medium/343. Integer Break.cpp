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

Question: 343. Integer Break
Topic : Linear-DP pattern=CoinChange
Problems : https://leetcode.com/problems/integer-break/

==============================> Explanation <=============================================

Idea is simple,

DP Linear Solution Coin Change 1D variant...
- We try every number between (1..N) and make pair of K and (N-K) and perform the multipication. But 
problem is that, We can still get maxProduct from (N-K) Number so we try that... Same as maxProduct of
K is possible..but here we fixed one point. Don't fix it also works.

- And we take maxProduct as N because number is itself the maximum with multiply by 1.

=>> Choice Diagram -> We Try all number to make combination of K and N-K such that product become maximum. 

==> Base Case -> N <= 1 -> return N. (0 and 1 max product is 0 and 1). 

==> Recurrance Relation: 
    
    maxProduct = N
    for(int k = 1; k < N; k++)
        maxProduct = max(maxProudct, K * Solve(N-K)); 

        OR

        maxProduct = max(maxProudct, solve(K) * Solve(N-K));

==============================> Apporach and Time Complexity <=============================================
1) Top-Down + Bottom-UP Linear-DP pattern=CoinChange:
Time: O(N^2)
Space: O(N)(Memorization)

*/


class Solution {

public:
    int integerBreak(int n, int t[]) {

        // Base case
        if(n <= 1)
            return n;

        if(t[n] != -1)
            return t[n];

        // body
        int max_answer = n;

        // possible pair element is from [1....n]
        for(int k = 1; k < n; k++) {
            
            // if remaining number is positive.
            if(n - k >= 0)
                max_answer = max(max_answer, k * integerBreak(n - k, t));       // fixed K.
        }
        return t[n] = max_answer;
    }

    int integerBreak(int n) {
       
        // Edge Case, 2 have max(1*1, 2*0) -> 1
        // Same as  , 3 have max(3*0, 1*2) -> 2
        if(n==2) return 1;
        if(n==3) return 2;
        
        int t[n+1];
        memset(t, -1, sizeof(t));

        return integerBreak(n, t);
    }
};


class Solution {
public:
    int integerBreak(int n) {

        if(n == 2) return 1;
        if(n == 3) return 2;

        int dp[n+1];
        memset(dp, 0, sizeof(dp));

        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++) {

            int max_product = i;

            for(int k = 0; k <= i; k++) {
                if(i - k >= 0) {
                    max_product = max(max_product, k * dp[i-k]);
                }
            }

            dp[i] = max_product;
        }

        return dp[n];
    }
};





class Solution {
public:
    int integerBreak(int n) {

        if(n == 2) return 1;
        if(n == 3) return 2;

        int dp[n+1];
        memset(dp, 0, sizeof(dp));

        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++) {

            int max_product = i;

            for(int k = 0; k <= i; k++) {
                if(i - k >= 0) {
                    max_product = max(max_product, dp[k] * dp[i-k]);
                }
            }

            dp[i] = max_product;
        }

        return dp[n];
    }
};