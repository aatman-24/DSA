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

Question: 1092. Shortest Common Supersequence
Topic : Top-Down Bottom-up Pattern=LCS
Problems : https://leetcode.com/problems/shortest-common-supersequence/

==============================> Explanation <=============================================
Dp variant = LCS

Shortest Common Supersequence is nothing but s1 + s2 - LCS. But here rathar than the length of
result we need the string itself.

Direct perform Top-Down Because it is LCS.

1) Choise Diagram: Same as LCS. 

2) Base Case: i == 0 || j == 0 -> dp[i][j] = 0.

3) Recurrance Relation:
   s[i] == s[j] -> dp[i][j] = dp[i-1][j-1] + 1
   s[i] != s[j] ->  dp[i][j] = max(dp[i-1][j], dp[i][j-1])

Check the code below...
==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern = LCS
Time: O(N^2)
Space: O(N^2)

*/

class Solution {
public:
    
    string shortestCommonSupersequence(string str1, string str2) {

        string common = lcs(str1, str2);
        int i = 0, j = 0;
        string res;

        for(char ch: common) {

            // Add until the ch 
            while(i < str1.size() && str1[i] != ch)
                res += str1[i++];

            // Add until the ch
            while(j < str2.size() && str2[j] != ch)
                res += str2[j++];

            res += ch;
            i++; j++;
        }

        // Remaining after into str1 and str2 from [i, n] and [j, m] 
        return res + str1.substr(i) + str2.substr(j);
    }


    string lcs(string str1, string str2) {

        int n = str1.size(), m = str2.size();

        // directly make the table of string.
        vector<vector<string>> dp(n+1, vector<string>(m+1, ""));

        for(int i= 1; i <= n; i++) {
            
            for(int j = 1; j <= m; j++) {
                
                if(str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + str1[i-1];
                }
                else {
                    if(dp[i-1][j].size() >= dp[i][j-1].size()) {
                        dp[i][j] = dp[i-1][j];
                    }
                    else {
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
        }


        return dp[n][m];
    }
};