#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

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

Question : 221. Maximal Square
Topic : DP
Problems : https://leetcode.com/problems/maximal-square/
*/


// Time Complexity - O(N*M). Using DP.
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int dp[n][m];
        memset(dp,0,sizeof(dp));

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') {

                    if(i == 0 || j == 0) {
                        ans = max(ans,1);
                        dp[i][j] = 1;
                    }
                    else {
                        int formedSquare =  min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                        ans = max(ans, formedSquare);
                        dp[i][j] = formedSquare;
                    }
                }
            }
        }

        return ans*ans; 
    }
};