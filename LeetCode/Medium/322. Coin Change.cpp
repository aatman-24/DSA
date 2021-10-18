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

Question: 322. Coin Change
Topic : Linear-DP 2D-DP pattern=Standard
Problems : https://leetcode.com/problems/coin-change/

==============================> Explanation <=============================================

1) First Apporach is Standard DP. Either take it coin or don't take the coin.

M -> Represent the total number of denominator(coins).
N -> Target Sum.

=>> Choice Diagram -> coins[i] <= N -> Take the current coins or don't take the current coins(move to the next coin).
                      Else don't take the coins.  

==> Base Case -> N == 0 no need of coins return 0.
                 N != 0 && M = 0 return INT_MAX... coins is finished and still N is remain.

==> Recurrance Relation: if(coins[i] <= N) min(solve(N-coins[i], M), solve(N, M-1)
                         else solve(N, M-1)


2) Linear DP.

- We try all the coins for the current N. And choose whichever give the minimum coin.

=>> Choice Diagram -> coins[i] < N, min_coins = min(min_coin, N - coins[i]), i = 0 -> M.  

==> Base Case -> N == 0 no need of coins return 0.
                 N < 0 return INT_MAX.

==> Recurrance Relation: 
                    min_coin = MAX_VALUE;
                    for (i = 0 -> M):
                        if(coins[i] <= N) 
                            min_coin = min(min_coin, solve(N - coins[i])
                    t[N] = min_coin



==============================> Apporach and Time Complexity <=============================================
1) Top-Down + Bottom-UP Linear-DP pattern=Standard:
Time: O(N^2)
Space: O(N)

2) Using Two State:
Time: O(N^2)
Space: O(N*M) M = 12.

*/

// Linear Top-Down
class Solution {
public:
    int MAX = 100000;

    int coinChange(vector<int> &coins, int N, int t[]) {

        if(N == 0)
            return 0;

        if(t[N] != -1)
            return t[N];

        int min_coin = MAX;

        // Try Every Coin if we could take it, and got minimum from all the possible ways.
        for(int i = 0; i < coins.size(); i++) {

            if(coins[i] <= N) {
                min_coin = min(min_coin, coinChange(coins, N - coins[i], t) + 1);
            }
        }
        return t[N] = min_coin; 
    }


    int coinChange(vector<int>& coins, int amount) {

        int t[amount+1];
        memset(t, -1, sizeof(t));

        int ans = coinChange(coins, amount, t);

        return ans == MAX ? -1: ans;
    }
};



// Linear Bottom-UP
class Solution {
public:
int MAX = 100000;

    
int coinChange(vector<int>& coins, int amount) {

    int dp[amount+1];
    dp[0] = 0;

    for(int i = 1; i <= amount; i++) {

        int min_coin = MAX;
        
        for(int j = 0; j < coins.size(); j++) {

            if(coins[j] <= i) {

                min_coin = min(min_coin, dp[i - coins[j]] + 1);
            }
        } 

        dp[i] = min_coin;
    }

    
    return dp[amount] == MAX ? -1 : dp[amount];
}

};





// 2 State Top-Down
class Solution {
public:
    int MAX = 100000;

    int coinChange(vector<int> &coins, int N, int M, int t[][13]) {

        // base cases. N is zero means no coins is required.
        if(N == 0)
            return 0;

        // If N is not Zero and M is zero no coins to complete Remaining N. So return MAX.
        if(M == 0)
            return MAX;

        if(t[N][M] != -1)
            return t[N][M];

        // If we can take the coins[M-1] then we have two choise either take it don't take it.
        if(coins[M-1] <= N) {
            t[N][M] = min(coinChange(coins, N-coins[M-1], M, t) + 1, coinChange(coins, N, M-1, t));
        }
        else {

            // Don't take it.
            t[N][M] = coinChange(coins, N, M-1, t);
        }

        return t[N][M]; 
    }


    int coinChange(vector<int>& coins, int amount) {

        int t[amount+1][13];
        memset(t, -1, sizeof(t));

        int ans = coinChange(coins, amount, coins.size(), t);

        return ans == MAX ? -1: ans;
    }
};


// 2 State Bottom-UP
class Solution {
public:
    int MAX = 100000;

    int coinChange(vector<int>& coins, int amount) {

        int M = coins.size(), N = amount;

        int dp[M+1][N+1];
        memset(dp, 0, sizeof(dp));

        sort(coins.begin(), coins.end());

        for(int j = 1; j <= N; j++) dp[1][j] = (j % coins[0] == 0) ? j / coins[0] : MAX;  
        for(int i = 0; i <= M; i++) dp[i][0] = 0;

        for(int j = 1; j <= N; j++) {
            for(int i = 2; i <= M; i++) {
                if(coins[i-1] <= j) {
                    dp[i][j] = min(dp[i][j-coins[i-1]] + 1, dp[i-1][j]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[M][N] == MAX ? -1 : dp[M][N];
    }
};