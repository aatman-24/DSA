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

Question: 413. Arithmetic Slices
Topic : Bottom-up Pattern=LIS
Problems : https://leetcode.com/problems/arithmetic-slices/

==============================> Explanation <=============================================

- Dp variant = LIS.

Cleary Given that Arithmetic subarrays has minimum length of 3 and formed in contiguous subsequence(subarray) So
We need to just check the wheather prev, prev, curr is arithmetic subarray or not. If yes then we can 
put dp[i] = dp[mid] + 1.

dp[i] indicate how many arithmetic subarrays ending at nums[i].


1) Choise Diagram: Keep track of how many subarray ending at the nums[i] with using dp[i]. 

0 1 2 3
1 2 3 4 -> dp[2] = 1 {1, 2, 3}
        -> dp[3] = 2 {2, 3, 4(1) + {(1,2,3)+ 4}(dp[2] + 1)}


2) Base Case: dp[0] = dp[1] = 0.
              
3) Recurrance Relation:

        if(nums[i-1] - nums[i-2] == nums[i] - nums[i-1])
            dp[i] = dp[i-1] + 1
        

Space optimization is possible, because dp[i] is only depend on dp[i-1].        

==============================> Apporach and Time Complexity <=============================================

1) Bottom-up Pattern=LIS
Time: O(N)
Space: O(N) / O(1)

*/



class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        int n = nums.size();
        if(n <= 2) 
            return 0;

        vector<int> dp(n, 0);
        dp[0] = dp[1] = 0;

        int total = 0;

        for(int i = 2; i < n; i++) {

            int mid = i - 1;

            if(nums[mid] - nums[mid-1] == nums[i] - nums[mid]) {
                dp[i] = dp[mid] + 1;
            }

            total += dp[i];

        }

        return total;
    }
};




class Solution {
public:
    
    int numberOfArithmeticSlices(vector<int>& nums) {

        int n = nums.size();

        if(n <= 2) 
            return 0;

        int dp = 0, totalSubarray = 0, endingAtIth;

        for(int i = 2; i < n; i++) {

            int mid = i - 1;
            endingAtIth = 0;

            if(nums[mid] - nums[mid-1] == nums[i] - nums[mid]) {
                endingAtIth = dp + 1;
            }


            totalSubarray += endingAtIth;
            dp = endingAtIth;
        }

        return totalSubarray;
    }
};