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

Question: 873. Length of Longest Fibonacci Subsequence
Topic : Bottom-up Pattern=LIS
Problems : https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/

==============================> Explanation <=============================================

Dp variant = LIS


Idea is that,

- We know that in Fibonacci, previous two term sum is next term.

Suppose, A[l] + A[r] = A[i]. (Then longest Fibonacci is atleast 3)

- We need to find all Pair of previous (A[l], A[r]) whose sum is A[i] and we choose the pair which provide us longest
series.


1) Choise Diagram: So, for the current i(>=2) we have to choose (l, r) pair (l, r < i) which extend the series 
by longest.

2) Base Case: Longest = 0, But If we find any pair then longest = 3, Or If we don't find then longest = 0. 

3) Recurrance Relation:

    A[l], A[r], A[i] -> A[l] + A[r] = A[i]

    dp[r][i] = dp[l][r] + 1   (Why we choose [r][i] because we store the value in sequence in dp.)
    
    dp[r][i] -> means ending at arr[i] and previous term is arr[r].
    dp[l][r] -> means ending at arr[r] and previous term is arr[l].

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern = LIS
Time: O(N^2)
Space: O(N^2)

*/

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

        int n = arr.size();


        // dp[i][j] -> Indicate that longest sequence which is ending at arr[j] and previous term is arr[i].
        int dp[n][n];
        memset(dp, 0, sizeof(dp));

        int longest = 0;

        for(int i = 2; i < n; i++) {

            // Two sum to find the A[l] + A[r] = A[i]... Array is sorted..
            int l = 0, r = i - 1;

            while(l < r) {

                int sum = arr[l] + arr[r];

                if(sum == arr[i]) {
                    dp[r][i] = max(dp[r][i], dp[l][r] + 1);
                    longest = max(longest, dp[r][i]);
                    l++; r--;
                }
                else if(sum < arr[i]) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }

        return longest == 0 ? 0 : longest + 2;
    }
};