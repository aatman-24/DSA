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

Question: 518. Coin Change 2
Topic : Bottom-up Pattern=Unbounded Knapsack
Problems : https://leetcode.com/problems/coin-change-2/

==============================> Explanation <=============================================
- Dp variant = Unbounded Knapsack,

- Actually Idea is very staright forward to use Unbounded Knapsack...

- Either we pick up or don't pick up. 

- As given we have INFINITE coins of the denominator so when we pick the current coin then we try to
pick the same coin again.

2) Base Case:
- At every step, N = 0 -> Return 1. Not picking is also one way to pick.  

3) Recurrance Relation: 
-   if(coins[i-1] <= j):
        dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]]
    else:
        dp[i][j] = dp[i-1][j]


==============================> Apporach and Time Complexity <=============================================

1) Bottom-up Pattern=LIS Version Linear DP
Time: O(N*M)
Space: O(N*M)

*/


class Solution {
public:

    int t[301][5001];

    int change(int index, int N, vector<int>& coins) {  
        
        // For 0 amount there is one way to choose the coin. (Not picking is also one way to pick)
        if(N == 0)
            return 1;

        if(t[index][N] != -1)
            return t[index][N];

        int ways = 0;

        // Here we can use the same coin again that's why we use the same index for the next
        // state if we add the current coin and if we don't add then we move the next element
        if(coins[index] <= N) {
            ways = change(index, N-coins[index], coins) + change(index-1, N, coins);
        }
        else {
            ways = change(index-1, N, coins);
        }


        return t[index][N] = ways;
    }

    int change(int amount, vector<int>& coins) {

        memset(t, -1, sizeof(t));

        return change(coins.size() - 1, amount, coins);
    }
};


class Solution {
public:
    
    int change(int amount, vector<int>& coins) {

        int M = coins.size(), N = amount;
        
        int dp[M+1][N+1];
        memset(dp, 0, sizeof(dp));

        // base case(Not picking is also one way to pick).
        for(int i = 0; i <= M; i++) {
            dp[i][0] = 1;
        }
        
        for(int j = 1; j <= N; j++) {
            for(int i = 1; i <= M; i++) {
                if(coins[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[M][N];
    }
};