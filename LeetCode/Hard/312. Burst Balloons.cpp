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

Question: 312. Burst Balloons
Topic : Top-Down Bottom-up Pattern=IntervalDP
Problems : https://leetcode.com/problems/burst-balloons/submissions/

==============================> Explanation <=============================================

- Dp variant = IntervalDP.

Intersting Problem...

I tried to do formal way of IntervalDP variant but it is not going to work here reason is that if 
arr = [3, 1, 5, 7] and if you burst the 1 ballon then next arr = [3, 5, 7].... and you choose from 
this subproblems but in standard way, 

[3] + arr[k-1] * arr[k] * arr[k+1] + [5, 7].... so (3, 5, 7) never tried and it's maxCoins is never 
tried so it wll affect the result.

So What to do now ?

- Think in reverse.

- For the given [i, j](left, right) find the ballons which is last can be burst and give maxCoins.

    (L)[1, 3, 1, 5, 7, 1](R)

    Find one of them (3, 1, 5, 7) which is burst at last when L(1) and R(1) is given so cost is

    nums[L] * nums[K] * nums[R]... Because K is last to burst so it is actually looks like [L, K, R].

    So overall Cost = maxCoins(L, K) + nums[L] * nums[K] * nums[R] + maxCoins(K, R) the left and right

    side of ballons cost is added.

- Try on pen and paper you got more insights.


1) Choise Diagram: 

    dp[i][j] = max(dp[i][j], dp[i][k] + arr[i] * arr[k] * arr[j] + dp[k][j]);

    dp[i][j] represent the maximum coins(points) to burst all the ballons between [i, j].


2) Base Case: (L + 1 == R) return 0.
              
3) Recurrance Relation:

   dp[i][j] = max(dp[i][j], dp[i][k] + arr[i] * arr[k] * arr[j] + dp[k][j]);
             
            
==============================> Apporach and Time Complexity <=============================================

1) Top-Down Bottom-up Pattern=
Time: O(N^2)
Space: O(N^2)

*/



int t[503][503];

class Solution {
public:

    int bursted(int left, int right, vector<int> &arr) {

        // base case (nothing between left to right to burst)
        if(left == right - 1)
            return 0;

        if(t[left][right] != -1)
            return t[left][right];


        // find the last ballon can be burst between (left, right) with maxCost.
        int maxProfit = 0;
        for(int k = left + 1; k < right; k++) {
            maxProfit = max(maxProfit, bursted(left, k, arr) + arr[left] * arr[k] * arr[right] + bursted(k, right, arr));
        }

        return t[left][right] = maxProfit;

    }



    int maxCoins(vector<int>& nums) {
            
        int N = nums.size();

        vector<int> arr(N+2, 0);

        arr[0] = 1, arr[N+1] = 1;
        for(int i = 0; i < N; i++) {
            arr[i+1] = nums[i];
        }

        memset(t, -1, sizeof(t));

        return bursted(0, N+1, arr);

    }
};




class Solution {
public:
    
    int maxCoins(vector<int>& nums) {
            
        int N = nums.size();

        vector<int> arr(N+2, 0);

        arr[0] = 1, arr[N+1] = 1;
        for(int i = 0; i < N; i++) {
            arr[i+1] = nums[i];
        }

        int dp[N+2][N+2];
        memset(dp, 0, sizeof(dp));

        for(int len = 2; len <= N + 1; len++) {         // used template with base case (left + 1 == right) so start with 2.

            for(int i = 0; i + len <= N + 1; i++) {

                int j = i + len;

                for(int k = i + 1; k < j ; k++) {

                    dp[i][j] = max(dp[i][j], dp[i][k] + arr[i] * arr[k] * arr[j] + dp[k][j]);

                }

            }

        }

        return dp[0][N+1];
    }
   
};