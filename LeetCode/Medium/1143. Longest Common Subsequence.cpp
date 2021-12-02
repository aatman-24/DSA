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

Question:  1143. Longest Common Subsequence
Topic : Top-Down Bottom-up Pattern=LCS
Problems : https://leetcode.com/problems/longest-common-subsequence/

==============================> Explanation <=============================================
- Dp variant = LCS Standard. 


1) Choise Diagram: Match ith and jth character or don't match then try to match (i-1, j) or (i, j-1).

2) Base Case: no string i < 0 || j < 0 return 0.
              
3) Recurrance Relation:
                
             if(s1[i] == s2[j])
                dp[i][j] = dp[i-1][j-1] + 1
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);


==============================> Apporach and Time Complexity <=============================================

1) Bottom-up Pattern=LCS
Time: O(N^2)
Space: O(N^2)

*/


class Solution {
public:
    int t[1001][1001];

    int longestCommonSubsequence(int i, int j, string s1, string s2) {

        if(i < 0 || j < 0)
            return 0;

        if(t[i][j] != -1)
            return t[i][j];

        if(s1[i] == s2[j]) {
            t[i][j] = longestCommonSubsequence(i-1, j-1, s1, s2) + 1;
        }
        else {
            t[i][j] = max(longestCommonSubsequence(i-1, j, s1, s2), longestCommonSubsequence(i, j-1, s1, s2));
        }

        return t[i][j];
    }



    int longestCommonSubsequence(string s1, string s2) {

        if(s2.size() < s1.size()) {
            string temp = s1;
            s1 = s2;
            s2 = temp;
        }

        memset(t, -1, sizeof(t));


        return longestCommonSubsequence(s1.size()-1, s2.size()-1, s1, s2);
    }


};



class Solution {
public:

    int longestCommonSubsequence(string s1, string s2) {

        if(s2.size() < s1.size()) {
            string temp = s1;
            s1 = s2;
            s2 = temp;
        }


        int m = s1.size(), n = s2.size();
        
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp)); 


        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m][n];

    }

};
