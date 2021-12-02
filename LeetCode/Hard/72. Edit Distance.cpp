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

Question: 72. Edit Distance
Topic : Top-Down Bottom-up Pattern=LCS
Problems : https://leetcode.com/problems/edit-distance/

==============================> Explanation <=============================================
Dp variant = LCS

s1 -> i, s2 -> j..

We try want to convert s1 into s2.

We can delete the ith char from s1.
We can add the jth char from s2.
We can replace the jth char with current ith char.

All take 1 unit of cost.



1) Choise Diagram: 
    if(s1[i] == s2[j])
        return solve(i-1, j-1)
    else
        return min(add, delete, replace) + 1.

delete -> (i-1, j)
add -> (i, j-1)
replace -> (i-1, j-1).


2) Base Case: i == 0 return j; j == 0 return i;

3) Recurrance Relation:
   s[i] == s[j] -> dp[i][j] = dp[i-1][j-1]
   s[i] != s[j] ->  dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1

Check the code below...
==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern = LCS
Time: O(N^2)
Space: O(N^2)

*/

// Top-Down
class Solution {
public:

    int t[501][501];

    int minDistance(int i, int j, string &s1, string &s2) {
        
        if(i == 0)
            return j;

        if(j == 0)
            return i;

        if(t[i][j] != -1)
            return t[i][j];

        int cost = 0;

        if(s1[i-1] == s2[j-1]) {
            cost = minDistance(i-1, j-1, s1, s2);
        }
        else {
            cost = min(min(minDistance(i-1, j, s1, s2), minDistance(i, j-1, s1, s2)), minDistance(i-1, j-1, s1, s2)) + 1;
        }

        return t[i][j] = cost;
    }


    int minDistance(string s1, string s2) {

        memset(t, -1, sizeof(t));

        return minDistance(s1.size(), s2.size(), s1, s2);

    }
};




// Bottom-Up
class Solution {
public:
   int minDistance(string s1, string s2) {

        int n = s1.size(), m = s2.size();

        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));

        // s1 -> N and s2 = Empty delete all the characters from s1.
        for(int i = 0; i <= n; i++)
            dp[i][0] = i;

        // s1 = Empty and s2 have length of m. Add all the characters from s2 -> s1.
        for(int j = 0; j <= m; j++)
            dp[0][j] = j;


        for(int i = 1; i <= n; i++) {
            
            for(int j = 1; j <= m; j++) {

                // match don't do anything.
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {

                    // dp[i-1][j] -> delete the ith char from s1.
                    // dp[i][j-1] -> add the jth char from s2 to s1.
                    // dp[i-1][j-1] -> Replace the jth char with ith char.
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                
            }
        
        }


        return dp[n][m];
    }
};