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

Question: 674. Longest Continuous Increasing Subsequence
Topic : Linear DP
Problems : https://leetcode.com/problems/longest-continuous-increasing-subsequence/

==============================> Explanation <=============================================

Simliar: Longest Increasing Subsequence.

But here we need Longest Continuous Increasing Subsequence.. So only current and previous element relationship
define Wheather the Sequence is increasing or start new Sequence.

- Only previous state define the dp state so we can reduce the space O(N) -> O(1).

==============================> Apporach and Time Complexity <=============================================

1) Linerar DP
Time: O(N)
Space: O(N) -> O(1)

*/

// With Extra Space.
class Solution {
public:

    int findLengthOfLCIS(vector<int>& nums) {
    
        int N = nums.size();
        vector<int> dp(N, 1);

        int longest = 1;
        for(int i = 1; i < N; i++) {
            if(nums[i-1] < nums[i]) {
                dp[i] = dp[i-1] + 1;
            }
            longest = max(longest, dp[i]);
        }
        return longest;
    }

};


// Without Extra Space.
class Solution {
public:

    int findLengthOfLCIS(vector<int>& nums) {
        
        int N = nums.size();
        
        int longest = 1, prev = 1, curr;

        for(int i = 1; i < N; i++) {
            
            if(nums[i-1] < nums[i]) {
                curr = prev + 1;
                prev = curr;
            }
            else {
                curr = 1;
                prev = 1;
            }
            longest = max(longest, curr);
        }
        return longest;
    }

};