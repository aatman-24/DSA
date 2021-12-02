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

Question: 368. Largest Divisible Subset
Topic : Bottom-up Pattern=Cadane
Problems : https://leetcode.com/problems/largest-divisible-subset/

==============================> Explanation <=============================================
Dp variant = Cadane DP. 

Logic is that,

- If given numbers is A -> B -> C, if B % A == 0 and C % B == 0 then, automatic C % A == 0(which no need to check).
 (Transitive Property)

- So we sort the array, so i < j then nums[i] < nums[j] and nums[i] could become divisor.

- And we use LIS logic.... dp[i] = dp[j] + 1 if(nums[i] % nums[j] == 0)

- But Here problem is that we also need that subset not only size.. so we use dfs logic of keeping previous
elements...(from which is best for current i) and lastly we derive that subset see below code..


1) Choise Diagram: if(nums[i] % nums[j] == 0) then we can expand the nums[j] series but we look all the
                    possible divisor which gives maxlen subset. (0 < =j <= i-1).

2) Base Case: every number is divisible by itself. minimum value of dp[i] = 1.

3) Recurrance Relation:
    
        for(int j = i - 1; j >= 0; j--)
            dp[i] = max(dp[i], dp[j]+1)

==============================> Apporach and Time Complexity <=============================================

1) Bottom-up  Pattern = LIS
Time: O(N)
Space: O(N)

*/


class Solution {

public:
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {


        if(nums.size() == 0 || nums.size() == 1)
            return nums;

        int N = nums.size();

        // dp[i] keep track of longest sequence which is ending at arr[i].
        // pre[i] keep track of previous index which is extended by arr[i]. 
        vector<int> dp(N, 1), pre(N, -1);

        int maxSubset = INT_MIN;

        // sort nums so every time just need to check j < i then nums[i] % nums[j] == 0 or not.
        sort(nums.begin(), nums.end());


        // same as LIS
        for(int i = 1; i < N; i++) {

            // keep track of previous term.
            int prev = -1;

            for(int j = i - 1; j >= 0; j--) {
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev = j;
                } 
            }

            // update both of this.
            maxSubset = max(maxSubset, dp[i]);

            pre[i] = prev;
        }



        // Find the acutal subset by using pre[] and maxSubset.
        vector<int> ans;
        int index = N - 1;

        // find the first element whose ending give maxSubset size subsets.
        while(dp[index] != maxSubset) index--;

        // simliar to DFS
        while(index != -1) {
            ans.push_back(nums[index]);
            index = pre[index];
        }

        // return ans.
        return ans;

    }
};