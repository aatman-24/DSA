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

Question: 718. Maximum Length of Repeated Subarray
Topic : Bottom-up Pattern=LCS
Problems : https://leetcode.com/problems/maximum-length-of-repeated-subarray/

==============================> Explanation <=============================================
Dp variant = Longest Common Substring.

- Same as Longest Common Substring but inplace of string here array of interger is given.

1) Choise Diagram: We know the differnce between Longest Common Subsequence and Longest Common Substring.

- We return the 0 if mismatch occur inplace of max(dp[i-1][j], dp[i][j-1]).

- And also keep track of maxLen because it can occur at any time.

2) Base Case: i == 0 || j == 0 -> dp[i][j] = 0.

3) Recurrance Relation:

   s[i] == s[j] -> dp[i][j] = dp[i-1][j-1] + 1
   s[i] != s[j] ->  dp[i][j] = 0

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern = LCS
Time: O(N^2)
Space: O(N^2)

*/

class Solution {
public:

    int findLength(vector<int>& nums1, vector<int>& nums2) {

        int N = nums1.size(), M = nums2.size();
        
        int dp[N+1][M+1];
        memset(dp, 0, sizeof(dp));

        int maxLen = 0;

        for(int i = 1; i <= N; i++) {
            
            for(int j = 1; j <= M; j++) {
                
                if(nums1[i-1] == nums2[j-1]) {
                    
                    dp[i][j] = dp[i-1][j-1] + 1;


                    // keep track of maxLen.
                    maxLen = max(maxLen, dp[i][j]);
                }
                else {


                    // substring break then return 0.
                    dp[i][j] = 0;
                }
            }
        }

        return maxLen;
    }
};