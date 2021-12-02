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

Question: 97. Interleaving String
Topic : Bottom-up Pattern=LCS
Problems : https://leetcode.com/problems/interleaving-string/

==============================> Explanation <=============================================
Dp variant = LCS

So s3 is interleaving of s1 and s2 so, and s3.size() == s1.size() + s2.size() and s3 is totally
formed using s1 and s2.


1) Choise Diagram: 
    
    1) If s3(k) is match with s1(i) -> (i-1, j, k-1) try to match with next char into s1.
    2) If s3(k) is match with s2(j) -> (i, j-1, k-1) try to match with next char into s2.
    3) If s3(k) is match with s1(i) and s2(j) -> we try both 1) and 2) and return true if any of this return true.
    4) If s3(k) is not match with any of s1(i) and s2(j) then, s3 have extra character so we
       directly return false.
    
    Simliar condition of LCS/Edit distacne.
    
2) Base Case: k == 0 -> return i == 0 && j == 0
              k is visited fully by s1 and s2 then at the end i = j = k is zero.

3) Recurrance Relation:
        if s1[i-1] == s3[k-1] && s2[j-1] == s3[k-1]
            dp[i][j] = dp[i-1][j] || dp[i][j-1]
        else if s1[i-1] == s3[k-1]
            dp[i][j] = dp[i-1][j]
        else if s2[j-1] == s3[i-1]
            dp[i][j] = dp[i][j-1]
        else
            dp[i][j] = 0(false)

I did not covert into the bottom-up, it is easy.

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern = LCS
Time: O(N^2)
Space: O(N^2)

*/

// Top-Down 2D.
class Solution {
public:
    int t[101][101];

    int isInterleave(int i, int j, int k, string &s1, string &s2, string &s3) {
        
        if(k == 0)
            return i == 0 && j == 0;

        if(t[i][j] != -1)
            return t[i][j];

        t[i][j] = 0;

        if(i >= 1 && j >= 1 && s1[i-1] == s3[k-1] && s2[j-1] == s3[k-1]) {
            t[i][j] = isInterleave(i-1, j, k-1, s1, s2, s3) || isInterleave(i, j-1, k-1, s1, s2, s3);
        }
        else if(i >= 1 && s1[i-1] == s3[k-1]) {
            t[i][j] = isInterleave(i-1, j, k-1, s1, s2, s3);
        }
        else if (j >= 1 && s2[j-1] == s3[k-1]) {
            t[i][j] = isInterleave(i, j-1, k-1, s1, s2, s3);
        }
        
        return t[i][j];

}


    bool isInterleave(string s1, string s2, string s3) {

       memset(t, -1, sizeof(t));

       return (bool)isInterleave(s1.size(), s2.size(), s3.size(), s1, s2, s3);
       
    }
};



// Bottom-up 2D.
class Solution {
public:

    bool isInterleave(string s1, string s2, string s3) {
    
        if(s3.length() != s1.length() + s2.length())
            return false;
        
        bool dp[s1.length()+1][s2.length()+1];
        
        for(int i=0; i<s1.length()+1; i++)
            for(int j=0; j< s2.length()+1; j++){
                if(i==0 && j==0)
                    dp[i][j] = true;
                else if(i == 0)
                    dp[i][j] = ( dp[i][j-1] && s2[j-1] == s3[i+j-1]);
                else if(j == 0)
                    dp[i][j] = ( dp[i-1][j] && s1[i-1] == s3[i+j-1]);
                else
                    dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1] ) || (dp[i][j-1] && s2[j-1] == s3[i+j-1] );
            }
            
        return dp[s1.length()][s2.length()];
    }

};
