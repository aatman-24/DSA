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

Question: 918. Maximum Sum Circular Subarray
Topic : prefixSum, Kadens 
Problems :  https://leetcode.com/problems/maximum-sum-circular-subarray/

==============================> Explanation <=============================================

Simliar: 1658. Minimum Operations to Reduce X to Zero


- Before solving this Question you have idea about how to find maxSum in Array(Without any rotation)
Answer is Kandane Algorithm(CP Manual)

Simple Idea is if we see that adding the next element maximize the sum then we take it if not then we
choose between  max(adding the element sum, element it self). Which avoid the negative sum and push
the current sum as zero until it produce the negative result.   

Example..

1 2 -1 -1 -1 -1 3 2 
1 3 2  1  0  0  3 5 (second 0 indicate we push the 0 as curSum).


So Here is trick that,


Case 1: (as above)
If our maxsum is rely in between (left, right).... Then we directly choose it.


Case 2: 
And In case is mixture of [left side + right Side](In rotation array) Then rathar than making algorithm
for that, 

We keep track of minSum between(left, right).... (Same as Case 1)
And at the end -> maxsum = Total - minSum.


So our answer is,

    max(Direct, Indirect)
    max(maxsum, total - minSum)


Edge Case Alert:

Suppose all elements are negative in that case,

    = max(negative, 0) (bcz total -> -x and minSum -> -x) -> (-x - (-x)) => 0
    = 0 (Which is wrong)

    That time we return the maxSum(Because that hold the single negative element) 


==============================> Apporach and Time Complexity <=============================================

2) Prefix Sum + Kadens Algorithm:
Time:O(N)
Space:O(1)

*/


class Solution {
public:

    int maxSubarraySumCircular(vector<int>& nums) {

        int total = 0, curMax = 0, maxSum = nums[0], curMin = 0, minSum = nums[0];

        for(int i = 0; i < nums.size(); i++) {

            // Keep track of curMax and maxSum.
            curMax = max(curMax+nums[i], nums[i]);
            maxSum = max(maxSum, curMax);

            // Keep track of curMax and maxSum.
            curMin = min(curMin+nums[i], nums[i]);
            minSum = min(minSum, curMin);

            total += nums[i];
        }   

        if(maxSum > 0)
            return max(maxSum, total - minSum);

        return maxSum;
    }
};