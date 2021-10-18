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

Question: 1218. Longest Arithmetic Subsequence of Given Difference
Topic : Bottom-up Pattern=MCM Version Linear DP
Problems : https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

==============================> Explanation <=============================================
- Dp variant = LIS,

- I directly come to the bottom-up solution. Here nums[i] is [-10^5, 10^5] so simple arr for
hashing is not possible for that reason we need to use map.

- Idea is same, We extend the AP.

If previousTermAp = (arr[i] - difference) is in the map then dp[arr[i]] = dp[previousTermAp] + 1
else mp[arr[i]] = 1. (Base case)

- In short, at every element dp[arr[i]] represent the longest AP is possible which end is arr[i].

2) Base Case:
- At every step, dp[i] = 1. Every element is length 1 AP Series.  

3) Recurrance Relation: 
- dp[arr[i]] = dp[previousTerm] + 1.


==============================> Apporach and Time Complexity <=============================================

1) Bottom-up Pattern=LIS Version Linear DP
Time: O(N)
Space: O(N)

*/




class Solution {

public:

    int longestSubsequence(vector<int>& arr, int dif) {

        unordered_map<int,int> dp;
        int longest = 0;

        for(int i = 0; i < arr.size(); i++) {

            // arr[i] - previousAPTerm = dif.
            int previousAPTerm = arr[i] - dif; 

            // check if we can extend.
            if(dp.count(previousAPTerm)) {
                dp[arr[i]] = dp[previousAPTerm] + 1;
            }

            // base case.
            if(!dp.count(arr[i]))
                dp[arr[i]] = 1;

            // keep track of maximum.
            longest = max(longest, dp[arr[i]]);
        }

        return longest;
    }
};