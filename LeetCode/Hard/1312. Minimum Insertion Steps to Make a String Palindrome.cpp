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

Question: 1312. Minimum Insertion Steps to Make a String Palindrome
Topic : Bottom-up Pattern=LCS
Problems : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

==============================> Explanation <=============================================
Dp variant = LCS

To make it palindrome either we have to add "GivenString-LCS" characters into given string or
delete it to make it palindrome.

1) Choise Diagram: Same as LCS.

2) Base Case: i == 0 || j == 0 -> return 0.

3) Recurrance Relation:
   s[i] == s[j] -> dp[i][j] = dp[i-1][j-1]
   s[i] != s[j] ->  dp[i][j] = min(dp[i-1][j], dp[i][j-1])

Check the code below...
==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern = LCS
Time: O(N^2)
Space: O(N^2)

*/

// Bottom-up
class Solution {
public:
    int minInsertions(string s1) {

        string s2 = s1;
        reverse(s2.begin(), s2.end());

        int n = s1.size();

        int dp[n+1][n+1];
        memset(dp, 0, sizeof(dp));


        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j]=  max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // total - LCS length.
        return n - dp[n][n];
    }
};