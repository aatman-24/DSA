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

Question: 516. Longest Palindromic Subsequence
Topic : Top-Down Pattern= LCS
Problems : https://leetcode.com/problems/longest-palindromic-subsequence/

==============================> Explanation <=============================================
Dp variant = LCS

LPS is nothing but LCS(S, reverse(S)). Return the MaxLength OF LCS. 

Direct perform Top-Down Because it is LCS.

1) Choise Diagram: Same as LCS. 

2) Base Case: i == 0 || j == 0 -> dp[i][j] = 0.

3) Recurrance Relation:
   s[i] == s[j] -> dp[i][j] = dp[i-1][j-1] + 1
   s[i] != s[j] ->  dp[i][j] = max(dp[i-1][j], dp[i][j-1])
   
==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern = LCS
Time: O(N^2)
Space: O(N^2)

*/


class Solution {
public:
    int longestPalindromeSubseq(string s1) {

        int N = s1.size();

        int dp[N+1][N+1];
        memset(dp, 0, sizeof(dp));

        string s2 = s1;
        reverse(s2.begin(), s2.end());

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }   
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[N][N];
    }
};