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

Question:  931. Minimum Falling Path Sum
Topic :Top-Down  Pattern= MultiDimesional DP
Problems : https://leetcode.com/problems/minimum-falling-path-sum/

==============================> Explanation <=============================================
- Dp variant = MultiDimesional DP, 

- Nothing special...

- Already Choise is given....

1) Choise Diagram: -> min((i+1, j-1), (i+1, j), (i+1, j+1)) whatever is minimum. 

2) Base Case: i >= mat.size() -> return 0.
              j >= mat[0].size() -> return INT_MAX. (Why check in the code)

             - Same logic is used in bottom-up check that.
              
3) Recurrance Relation:
    
        t[i][j] = min(t[i+1][j-1], t[i+1][j], t[i+1][j+1]) + mat[i][j]

Space optimization is possible. -> O(N) (Why? You knew already.)

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Bottom-UP Pattern= MultiDimesional DP
Time: O(N^2)
Space: O(N^2)


1) Bottom-UP Pattern= MultiDimesional DP
Time: O(N^2)
Space: O(N)

*/

// 0 -> N.
class Solution {
public:
    
    int t[101][101];

    int minFallingPathSum(int i, int j, vector<vector<int>> &matrix) {
        
        // Out of row. Because all three function call is out of row so must return 0 here.
        if(i >= matrix.size())
            return 0;

        // Return INT_MAX because there are some function call(mainly middle one) which is not Out of boundary. 
        // If return 0 then the function select 0 as min value.
        if(j < 0 || j >= matrix.size())
            return INT_MAX;

        if(t[i][j] != -1)
            return t[i][j];

        return t[i][j] = min({minFallingPathSum(i+1, j-1, matrix), minFallingPathSum(i+1, j, matrix), minFallingPathSum(i+1, j+1, matrix)}) + matrix[i][j];

    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
    
        int n = matrix.size();
        
        memset(t, -1, sizeof(t));

        int ans = INT_MAX;
        for(int j = 0; j < n; j++) {
            ans = min(ans, minFallingPathSum(0, j, matrix));
        }
        
        return ans;
    }
};


// N -> 0.
class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
    
        int n = matrix.size();
        
        int dp[n][n+2];

        // add two column 0th and (n+1)th as INT_MAX;
        for(int i = 0; i < n; i++) {
            dp[i][0] = INT_MAX;
            dp[i][n+1] = INT_MAX;
        }

        // set the last row as it is
        for(int j = 1; j <= n; j++) {
            dp[n-1][j] = matrix[n-1][j-1];
        }

        
        for(int i = n-2; i >= 0; i--) {

            for(int j = 1; j <= n; j++) {       // 1 based index.

                dp[i][j] = min({dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]}) + matrix[i][j-1];

            }
        }
        
        
        // choose the minimum from the 0th row.
        int ans = INT_MAX;
        for(int j = 1; j <= n; j++) {
            ans = min(ans, dp[0][j]);
        }
    
        return ans;

    }
};


931. Minimum Falling Path Sum

// 0 -> N.
class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
    
        int n = matrix.size();
        
        int dp[n][n+2];

        // add two column 0th and (n+1)th as INT_MAX;
        for(int i = 0; i < n; i++) {
            dp[i][0] = INT_MAX;
            dp[i][n+1] = INT_MAX;
        }

        // set the first row as it is
        for(int j = 1; j <= n; j++) {
            dp[0][j] = matrix[0][j-1];
        }

        
        for(int i = 1; i < n; i++) {

            for(int j = 1; j <= n; j++) {       // 1 based index.

                dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]}) + matrix[i][j-1];

            }
        }
        
        
        // choose the minimum from the n-1th row.
        int ans = INT_MAX;
        for(int j = 1; j <= n; j++) {
            ans = min(ans, dp[n-1][j]);
        }
    
        return ans;

    }
};



// O(N) space.
class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
    
        int n = matrix.size();
        
        vector<int> dp(n+2,  0);

        // first ans last column as INT_MAX.
        dp[0] = dp[n+1] = INT_MAX;

        // first row as it is.
        for(int j = 1; j <= n; j++) {
            dp[j] = matrix[0][j-1];
        }

        // start with second row.
        for(int i = 1; i < n; i++) {

            // make duplicate copy.
            vector<int> copy_dp = dp;

            for(int j = 1; j <= n; j++) {       // 1 based index.

                copy_dp[j] = min({dp[j-1], dp[j], dp[j+1]}) + matrix[i][j-1];

            }

            // swap the value.
            dp = copy_dp;
        }
        
        
        // choose the minimum from the n-1th row.
        int ans = INT_MAX;
        for(int j = 1; j <= n; j++) {
            ans = min(ans, dp[j]);
        }
    
        return ans;

    }
};