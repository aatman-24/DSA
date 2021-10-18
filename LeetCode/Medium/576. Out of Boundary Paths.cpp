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

Question: 576. Out of Boundary Paths
Topic :Top-Down Bottom-up Pattern= MultiDimesional DP
Problems : https://leetcode.com/problems/out-of-boundary-paths/

==============================> Explanation <=============================================
- Dp variant = MultiDimesional DP.

1) Choise Diagram: It is clear indication that the total answer is counted moves wise.
    Because, if we are at [i][j] at some moves then, we count all the ways such that,
    [i][j] can hit the ball out of wall using that moves.

    you can check the test case.. I got the idea from that.


2) Base Case: Out of boundary any case then return 1 directly.
              moves == 0 then return 0 no way to hit out of wall using 0 moves.
              

3) Recurrance Relation:
    
        dp[moves][i][j] = dp[moves-1][xx][yy] -> xx and yy is four direction from (i, j).

- Space optimization is possible because we just using the previous level information.

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern=Target Sum, Coin Change
Time: O(N^3)
Space: O(N^3)

2) Bottom-up Pattern= Target Sum, Coin Change
Time: O(N^3)
Space: O(N^2)

*/


#define mod 1000000007

class Solution {
public:

        int x[4] = {1, 0, -1, 0};
        int y[4] = {0, 1, 0, -1};


        long t[51][52][52];


    long findPathsA(int i, int j, int moves, int m, int n) {

        // moves > 0 and hit the boundary then return 1.
        if(i < 0 || j < 0 || i >= m || j >= n)
            return 1;
        
        // moves is zero then don't hit the ball out of boundary.
        if(moves == 0)
            return 0;

        if(t[moves][i][j] != -1)
            return t[moves][i][j];

        long ways = 0;

        for(int k = 0; k < 4; k++) {

            int xx = x[k] + i;
            int yy = y[k] + j;

            ways += (findPathsA(xx, yy, moves-1, m, n) % mod);
        }

        return t[moves][i][j] = ways % mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        memset(t, -1, sizeof(t));

        return (int)findPathsA(startRow, startColumn, maxMove, m, n);

    }
};




#define mod 1000000007

class Solution {
public:

    int x[4] = {1, 0, -1, 0};
    int y[4] = {0, 1, 0, -1};


  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        long dp[maxMove+1][m+1][n+1];
        memset(dp, 0, sizeof(dp));

        long ans = 0;

        for(int k = 1; k <= maxMove; k++) {

            for(int i = 0; i < m; i++) {
            
                for(int j = 0; j < n; j++) {

                        long ways = 0;

                        for(int p = 0; p < 4; p++) {

                            int xx = x[p] + i;
                            int yy = y[p] + j;

                            // out of boundary.
                            if(xx < 0 || yy < 0 || xx >= m || yy >= n) {
                                ways++;
                                continue;
                            }

                            ways += dp[k-1][xx][yy];
                        }
                    
                    dp[k][i][j] += (ways % mod);
                }

            }

        }

        return (int)dp[maxMove][startRow][startColumn] % mod;
    }
};



#define mod 1000000007

class Solution {
public:

    int x[4] = {1, 0, -1, 0};
    int y[4] = {0, 1, 0, -1};


  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        vector<vector<long>> dp(m+1, vector<long>(n+1, 0));
        long ans = 0;

        for(int k = 1; k <= maxMove; k++) {

            // store the current moves answer here.
            vector<vector<long>> cur(m+1, vector<long>(n+1, 0));

            for(int i = 0; i < m; i++) {
            
                for(int j = 0; j < n; j++) {

                        long ways = 0;

                        for(int p = 0; p < 4; p++) {

                            int xx = x[p] + i;
                            int yy = y[p] + j;

                            // out of boundary.
                            if(xx < 0 || yy < 0 || xx >= m || yy >= n) {
                                ways++;
                                continue;
                            }

                            ways += dp[xx][yy];
                        }
                    
                    cur[i][j] += (ways % mod);
                }

            }

            // swap the cur and dp.
            dp = cur;
        }

        return (int)dp[startRow][startColumn] % mod;
    }
};