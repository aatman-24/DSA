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

Question: 1043. Partition Array for Maximum Sum
Topic : Top-Down Bottom-up Pattern=MCM Version Linear DP
Problems : https://leetcode.com/problems/partition-array-for-maximum-sum/


==============================> Explanation <=============================================
- Dp variant of MCM,
-from where putting the cut give the maximum value for the current state + after the next state.
-for the current state we can make the cut in range from (i,i+k).. so we check at every index
which give the maxSum.
-And maxSum is counted directly check the code.


1) Choice Diagram(0 based index):
- put the cut in range between [i, i+k] and select which give the maxValue.


2) Base Case:
- N >= arr.size() -> return 0.(min value.)

3) Recurrance Relation: 

for(int i = index; i < min(n, index+k); i++) {
    maxelement = max(maxElement, arr[i]);
    maxsum = max(maxsum, (i - index+1) * maxelement + nextState(i+1, arr));
}

==============================> Apporach and Time Complexity <=============================================

0) Brute Force take O(2^N).. Using Recursion...

1) Top-Down Bottom-up Pattern=MCM Version Linear DP
Time: O(N)
Space: O(N)

*/




class Solution {

public:

    int t[501];

    int maxSumAfterPartitioning(int index, vector<int>& arr, int k) {

        // for finding max Value we return min value 0.
        if(index >= arr.size())
            return 0;

        if(t[index] != -1)
            return t[index];

        int n = arr.size();
        int maxValue = 0, maxSum = 0;

        // Here we try to make cut at every index between (index, index+k) and see
        // which is the max value for the current subarray and 
        // give maxSum using that element as maxValue + after remaining array.
        for(int i = index; i < min(n, index+k); i++) {
            
            maxValue = max(maxValue, arr[i]);

            // In the next Subarray we don't choose the current maxValue.
            maxSum = max(maxSum, (i - index + 1) * maxValue + maxSumAfterPartitioning(i+1, arr, k));
        }

        return t[index] = maxSum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        memset(t, -1, sizeof(t));
        return maxSumAfterPartitioning(0, arr, k);
    }
};





class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        int n = arr.size();
        int dp[n+1];

        // base case.
        dp[n] = 0;

        for(int i = n - 1; i >= 0; i--) {

            // same as top-down
            int maxValue = 0, maxSum = 0;
            for(int j = i; j < min(n, i+k); j++) {
                maxValue = max(maxValue, arr[j]);
                maxSum = max(maxSum, (j - i + 1) * maxValue + dp[j+1]);
            }
            dp[i] = maxSum;
        }

        return dp[0];
    }
};