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

Question: 64. Minimum Path Sum
Topic : Top-Down Pattern=MatrixReachtoTarget
Problems : https://leetcode.com/problems/minimum-path-sum/

==============================> Explanation <=============================================
- Already given Choise diagram,

Standard problem on dpOnPath...

I solved both ways.... [0][0] -> [m-1][n-1] and
                       [m-1][n-1] -> [0][0].

Only Equation is changed check the code.

I written here for the backward method -> [m-1][n-1] -> [0][0].

1) Choise Diagram: 
Select from the (i-1,j) or (i, j-1) which every is minimum. (backward)
Select from the (i+1,j) or (i, j+1) which every is minimum. (forward)

2) Base Case: Either [0][0] or [m-1][n-1] is base case..just return grid[i][j] that time.

3) Recurrence Relation: 
S[i][j] = min(S[i-1][j], S[i][j-1]) + grid[i][j](backward)
S[i][j] = min(S[i+1][j], S[i][j+1]) + grid[i][j](forward)

Handled all the boundary case in bottom-up.

I also write down O(1)(inplace solution).

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Bottom-up Pattern=dpOnPath
Time: O(N*M)
Space: O(N*M)

1) Top-Down Pattern=dpOnPath inplace
Time: O(N*M)
Space: O(1)

*/

class Solution {
public:

    int t[201][201];

    int MAX = 100000;

    int minPathSum(int i, int j, vector<vector<int>> &grid) {

        if(i == grid.size() - 1 && j == grid[0].size() - 1)
            return grid[i][j];

        if(i >= grid.size() || j >= grid[0].size())
            return 100000;

        if(t[i][j] != -1)
            return t[i][j];

        return t[i][j] = min(minPathSum(i+1, j, grid), minPathSum(i, j+1, grid)) + grid[i][j];
    }


    int minPathSum(vector<vector<int>>& grid) {

        memset(t, -1, sizeof(t));

        return minPathSum(0, 0, grid);
    }

};



class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));

        for(int i = m-1; i >= 0; i--) {

            for(int j = n-1; j >= 0; j--) {

                dp[i][j] = grid[i][j];

                if(i+1 < m && j+1 < n) {
                    dp[i][j] += min(dp[i+1][j], dp[i][j+1]);
                } 
                else if(i + 1 < m) {
                    dp[i][j] += dp[i+1][j];
                }
                else if(j + 1 < n) {
                    dp[i][j] += dp[i][j+1];
                }
            }
        }
        
        return dp[0][0];
    }
};




class Solution {
public:

    int t[201][201];

    int MAX = 100000;

    int minPathSum(int i, int j, vector<vector<int>> &grid) {

        if(i == 0 && j == 0)
            return grid[i][j];

        if(i < 0 || j < 0)
            return 100000;

        if(t[i][j] != -1)
            return t[i][j];

        return t[i][j] = min(minPathSum(i-1, j, grid), minPathSum(i, j-1, grid)) + grid[i][j];
    }


    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        memset(t, -1, sizeof(t));

        return minPathSum(m-1, n-1, grid);
    }

};



class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                dp[i][j] = grid[i][j];

                if(i-1 >= 0 && j-1 >= 0) {
                    dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
                } 
                else if(i - 1 >= 0) {
                    dp[i][j] += dp[i-1][j];
                }
                else if(j - 1 >= 0) {
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};



class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        for(int j = 1; j < n; j++) grid[0][j] += grid[0][j-1];
        for(int i = 1; i < m; i++) grid[i][0] += grid[i-1][0];


        for(int i = 1; i < m; i++) {

            for(int j = 1; j < n; j++) {

                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[m-1][n-1];
    }
};
