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

Question:  673. Number of Longest Increasing Subsequence
Topic : Bottom-up Pattern=LIS
Problems : https://leetcode.com/problems/number-of-longest-increasing-subsequence/

==============================> Explanation <=============================================
- Dp variant = LIS version, 

That's Why Bottom-up performed direct.

Here, we need to find count of longest subsequence.

As per the LIS we find all the previous number which can be extended and give longest sub-seq.
But here we also keep track of number of such sub-seq.

1) Choise Diagram: 

2) Base Case: dp[0][0] = dp[0][1] = 1. 
              And every number is itself LIS of length 1 and count 1.
              
3) Recurrance Relation:
            
                if(nums[j] < nums[i])

                    if(dp[j][0] + 1 > dp[i][0])
                        dp[i][0] = dp[j][0] + 1
                        dp[i][1] = dp[j][1]

                    if(dp[j][0] + 1 == dp[i][0])
                        dp[i][1] += dp[j][1]


==============================> Apporach and Time Complexity <=============================================

1) Bottom-up Pattern=LIS
Time: O(N^2)
Space: O(N^2)

*/


class Solution {
public:

    int findNumberOfLIS(vector<int>& nums) {

        int N = nums.size();
        
        // dp[i][0] -> Indicate the longest length ending at nums[i].
        // dp[i][1] -> Number of subsequence which has longest length.
        int dp[N][2];
        memset(dp, 0, sizeof(dp));

        // for the num[0] has 1 subsequence of 1 length.
        dp[0][0] = dp[0][1] = 1;

        // Keep track of maxLen.
        int maxLen = 1;

        for(int i = 1; i < nums.size(); i++) {

            // Ending at nums[i] the longestLength is zero and count = 0.
            int curLongest = 0, count = 0;

            for(int j = i-1; j >= 0; j--) {
                
                // We can extend the nums[j].
                if(nums[j] < nums[i]) {
                
                    // We can get longest subsequence by extending nums[j].
                    if(dp[j][0] + 1 > curLongest) {
                        curLongest = dp[j][0] + 1;

                        // so all the subsequence of which end at num[j] is directly adding into count.
                        count = dp[j][1];
                    }

                    // Found the nums[j] which extension also result into the curLongest.
                    // So Just add all subsequence which give curLongest length.
                    if(dp[j][0] + 1 == curLongest)
                        count += dp[j][1];
                }

                // Adding current nums[i] increase the sequence.
                dp[i][0] = curLongest + 1;

                // It could not be zero atleast 1 for the current number.
                dp[i][1] = max(count, 1);


                // keep track of maxLen.
                maxLen = max(maxLen, dp[i][0]);
            }
        }


        // count all the subsequence which have maxLen.
        int ans = 0;
        for(int i = 0; i < N; i++)
            if(maxLen == dp[i][0])
                ans += dp[i][1];

        return ans;
    }
};