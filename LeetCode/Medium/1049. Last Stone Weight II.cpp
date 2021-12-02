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

Question: 1049. Last Stone Weight II
Topic : Top-Down Bottom-up Pattern=UnboundedKnapsack
Problems : https://leetcode.com/problems/last-stone-weight-ii/

==============================> Explanation <=============================================

- Dp variant = UnboundedKnapsack.

Same Problem:
    Paritition the array into two subset such that it differnce is smaller
    find....min(s1-s2)

Aditya Veram Playlist...

Suppose, We have two subset s1 and s2... 

    ans = min(s1 - s2)
    s1 + s2 = T(total sum)

    ans = min(T-s2-s2)
        = min(T-2*s2)


Now we find all the combination which can be s2... using given numbers. and find above equation min value.


S2 can not be exceeds T/2... Because 0 < S2 <= T/2 <= s1 < T....


1) Choise Diagram: 

see above.

2) Base Case: dp[i][0] = 1. (With any number sum = 0 is possible.)
              
3) Recurrance Relation:
                
        dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]

- Space optimization is possible...

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern=UnboundedKnapsack
Time: O(N^2)
Space: O(N^2) can be reduce to O(N)


*/


class Solution {
public:

    int lastStoneWeightII(vector<int>& nums) {
    
        if(nums.size() == 1)
            return nums[0];
        
        int T = 0, N = nums.size();
        for(int num: nums)
            T += num;

        sort(nums.begin(), nums.end());

        int dp[N+1][(T/2)+1];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i <= N; i++)
            dp[i][0] = 1;

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= T/2; j++) {
                if(nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }   
            }
        }


        int diff = INT_MAX;

        for(int i = 1; i <= T/2; i++) {
            if(dp[N][i] == 1) {
                diff = min(diff, T - 2*i);
            }

        }

        return diff;
    }
};