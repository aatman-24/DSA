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

Question: 198. House Robber
Topic : Linear-DP pattern=Fibonaci
Problems : https://leetcode.com/problems/house-robber/

==============================> Explanation <=============================================

First insight dyanmic programming,

- We are at ith house then, simply we can rob the current house i ...Rob(i) + Rob(i-2).
  Or don't rob the current house....Rob the previous house.... Rob(i-1)  

=>> Choice Diagram -> N -> max(Rob(N-1), Rob(N-2)+Money[N]) 

==> Base Case -> N < 0 -> Return 0. For max function Base case return minimum value. 

==> Recurrance Relation: F(N) = max(F(N-1), F(N-2)+Cost[N])

==============================> Apporach and Time Complexity <=============================================
1) Top-Down + Bottom-UP Linear-DP pattern=Fibonaci:
Time: O(N)
Space: O(N)(Memorization)

2) Using Two State:
Time: O(N)
Space: O(1)

*/

// Top-Down (memorization)
class Solution {
public:
    int mostLoot(int n, vector<int>& nums, int t[]) {

        if(n < 0)
            return 0;

        if(t[n] != -1)
            return t[n];

        return t[n] = max(mostLoot(n-1, nums, t), mostLoot(n-2, nums, t) + nums[n]);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        int t[nums.size()];
        memset(t, -1, sizeof(t));

        return mostLoot(n-1, nums, t);
    }
};

// Bottom-up 
class Solution {
public:

    int rob(vector<int>& nums) {

        int n = nums.size();

        int dp[n+1];
        memset(dp, 0, sizeof(dp));

        // Base case
        dp[0] = 0;          // n < 0 -> That time used.     
        dp[1] = nums[0];    // n == 0 -> That time used.

        for(int i = 2; i <= n; i++) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);   // Dp Table is 1 based index and nums is 0th based index.
        }

        return dp[n];
    }
};


// Using Two Variable as state.
class Solution {
public:

    int rob(vector<int>& nums) {

        int n = nums.size();

        // Base case
        int prev2 = 0;          // n < 0 -> That time used.
        int prev1 = nums[0];    // n == 0 -> That time used.

        for(int i = 2; i <= n; i++) {
            int current = max(prev1, prev2+nums[i-1]);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};