#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

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

Question : 560. Subarray Sum Equals K
Topic : PrefixSum, Array
Problems : https://leetcode.com/problems/subarray-sum-equals-k//
/*
==============================> Explanation <=============================================
6 -3 3 2 -5 6

Subarray:
6 -3
3
6 -3 3 2 -5
-3 3 2 -5 6
2 -5 6

- we maintain the map<prefix_sum, occurace>. and When we need the
sum = current_sum - k and we found into the the map. Means we 
directly count it.


Ex...

6 -3 3 2 -5 6
6 3 6 8 3 9



For the last element sum = 9. 
map = {6,2}, {3,2}, {8,1}


so we search for 9 - 3(k) = 6 so we found total 2 times.


1) 

6 [-3 3 2 -5 6]
6(here)  3 6 8  3 9

so -3 + 3 + 2 -5 + 6 = 3

2)
6 -3 3       [2 -5 6]
6  3 6(here) 8  3 9

so 2 - 5 + 6 = 3.

conclusion = whenever we find the sum - k into the map means we 
subtract the subarray which sum is = (sum - k) remaining is the
our ans.

*/

/*
==============================> Edge Case <=============================================

Edge case is that whenever we found the cursum = k. That time 
we also check for (cursum - k) because it is possible that 
(cursum - k) = 0. (0 is sum of subarray into our array) so need to 
count that also.


*/

// Apporach 1: O(N^3)
// - Use Two For loop for maintain the start and end of the subarray. And 
// using third loop calculate sum from [start, end].


// Apporach 2: O(N^2)
// - Use Two For loop for maintain the start and end of the subarray. And 
// use prefix sum to directly calcuate the sum from [start, end]. 

// Approach 3: O(N)
// - maintain the prefix sum + maintain the prefix sum into the map.
// If current sum is = sum then we find the total number of occurace of
// map[sum-k] into the map. and count it.



class Solution {
public:

    // O(N) - O(N)
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int sum = 0, subarrayCnt = 0;
        
        for(int n : nums) {
            sum += n;

            // from the start of array if sum is k.
            if(sum == k) subarrayCnt++;

            // this is not from start of the array.
            // if sum of subarray of array which we try to subtract 
            // or remove from the [start... currentSubarray] subarray.
            // if we found.
            if(mp.find(sum - k) != mp.end()) subarrayCnt += mp[sum-k];

            // we try to store the occurace of prefix sum.
            if(mp.find(sum) == mp.end()) mp[sum] = 1;
            else mp[sum] += 1;
        }
        return subarrayCnt;
    }
};