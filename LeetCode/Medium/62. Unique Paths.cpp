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

Question: 62. Unique Paths
Topic : Top-Down Bottom-up Pattern=dpOnPath LinearSpace
Problems : https://leetcode.com/problems/unique-paths/
==============================> Explanation <=============================================
choice digram is already given, either go right or down.

Standard problem on dpOnPath...

Check out 64. Minimum Path Sum... Where Both Forward([0][0] -> [m-1][n-1]) and backward([m-1][n-1] -> [0][0])
has been sovled. 

Here mention that need total number of way so just add all possible solution which is fesible at
given time.
                       .
Here I choose to go from -> (m-1,n-1) --> (0,0)

1) Choise Diagram: 
Add both ways (i-1,j) and (i, j-1). Because we can go from (i,j) to both the position. (backward)


2) Base Case: dp[0][0] = 1, Because that means that one way to reach (0,0)
            - if(i < 0 || j < 0) that means no way we return 0.

3) Recurrence Relation: 
S[i][j] = S[i-1][j] + S[i][j-1]

Again space optimization, Idea comes from above equation only last row and column entry needed.
So we use O(N) pre_row(previous row) and column is already in current row so need for that.

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Bottom-up Pattern=dpOnPath
Time: O(N*M)
Space: O(N*M)

1) Top-Down Pattern=dpOnPath With Linear Space
Time: O(N*M)
Space: O(N)

*/

class Solution {
public:
    int t[101][101];

    int uniquePathsCount(int i, int j) {

        if(i == 0 && j == 0)
            return 1;

        if(i < 0 || j < 0)
            return 0;

        if(t[i][j] != -1)
            return t[i][j];

        return t[i][j] = uniquePathsCount(i-1, j) + uniquePathsCount(i, j-1);
    }

    int uniquePaths(int m, int n) {

        memset(t, -1, sizeof(t));

        return uniquePathsCount(m-1, n-1);
    }
};


class Solution {
public:

    int uniquePaths(int m, int n) {

        int dp[m][n];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
            
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(i-1 >= 0)
                    dp[i][j] += dp[i-1][j];

                if(j-1 >= 0)
                    dp[i][j] += dp[i][j-1];
            }
        }    

        return dp[m-1][n-1];
    }
};


class Solution {
public:
    int uniquePaths(int m, int n) {

        // all the dp[i][0] and dp[0][j] has one way to reach to the (0,0) either in single
        // column or row so directly use that. and start from row=1 and col=1.
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> pre(n, 1), cur(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cur[j] = pre[j] + cur[j - 1];
            }
            swap(pre, cur);
        }
        return pre[n - 1];
    }
};