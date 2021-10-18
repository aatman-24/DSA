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

Question: 63. Unique Paths II
Topic : Top-Down Pattern=MatrixReachtoTarget
Problems : https://leetcode.com/problems/unique-paths-ii/
==============================> Explanation <=============================================

Parent Problem: 62. Unique Paths

- Here included cell which is obstacle we don't count it. It break our all paths there.
dp[i][j] = 0. for such cell.

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Bottom-up Pattern=dpOnPath
Time: O(N*M)
Space: O(N*M)

*/



class Solution {
public:
    int t[101][101];

    int uniquePathsWithObstacles(int i, int j, vector<vector<int>> &grid) {
        
        // Our path can not include or pass through the obstacle.
        if(i < 0 || j < 0 || grid[i][j] == 1)
            return 0;
        
        if(i == 0 && j == 0)
            return 1;

        if(t[i][j] != -1)
            return t[i][j];

        return t[i][j] = uniquePathsWithObstacles(i-1, j, grid) + uniquePathsWithObstacles(i, j-1, grid);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        memset(t, -1, sizeof(t));

        return uniquePathsWithObstacles(m-1, n-1, obstacleGrid);

    }
};


class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        if(grid[0][0] == 1 || grid[m-1][n-1] == 1)
            return 0;

        int dp[m][n];
        memset(dp, 0, sizeof(dp));

        dp[0][0] = 1;

        for(int i = 0; i < m; i++) {
            
            for(int j = 0; j < n; j++) {

                // obstacle dp[i][j] = 0.
                if(grid[i][j] == 1)
                    continue;

                if(i-1 >= 0 && j-1 >= 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                else if(i - 1 >= 0) {
                    dp[i][j] = dp[i-1][j];
                }
                else if(j - 1 >= 0) {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};


