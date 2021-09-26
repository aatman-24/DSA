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

Question: 1658. Minimum Operations to Reduce X to Zero
Topic : prefixSum, Sliding Window
Problems :  https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

==============================> Explanation <=============================================
1) BFS: We can solve this problem using BFS. Either first or last element is subtracted from the current X 
so we add both this state into the current queue and also maintain the visited element so don't same
state again visited. But it will take More Time.

Second Solution Ideas is that,

                    x1 x2 x3 x4 x5 x6 x7

Here, we need minimum opreation to make X -> 0. We take either from the first or last of array element which
indicate that we need subarray whose sum is equal to X but subarray is must be from,

Full -> Start
Full -> End
Half + Half -> Start + End.

Which is diffcult to find and complex algorithm needed. But we can convert this problem into some other,

Find the smallest subarray whose Sum is X = N(length of array) - Find the longest subarray whose Sum is SUM(array) - X. 


Longest subarray with Target sum can be found using,

1) prefix sum method

2) And here element of array is not negative so we can also go for the sliding window.


==============================> Apporach and Time Complexity <=============================================
1) BFS:
Time: O(2^N) -> [1, 2, 4, 8, 16, 32...2^N-1]Calls at Each level.
Space: O(2^N)

2) Prefix Sum:
Time:O(N)
Space:O(N)

3) Sliding Window:
Time: O(N)
Space: O(1) 


*/


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int sum = 0;
        for(int num: nums)
            sum += num;

        /*Problem : Lognest Subarray With Given Sum equals to target */

        int target = sum - x, ans = 0, i = 0;
        
        // All Elements are positive so negative sum can not be achieved. Return -1.
        if(target < 0)
            return -1;
        
        // If target is zero means that all the array elements are part of our solution because we need longest subarray.
        if(target == 0)
            return nums.size();
        
        
        for(int j = 0; j < nums.size(); j++) {
            
            target -= nums[j];
            
            while(target < 0) {
                target += nums[i++];
            }
            
            if(target == 0)
                ans = max(ans, j + 1 - i);
        }

        // If not found any subarray return -1.
        if(ans == 0)
            return -1;
        
        // shortest subarray with size X = array.size - (longest subarray with sum = SUM(Array) - X)
        return nums.size() - ans;
    }
};



class Solution {
public:

    int minOperations(vector<int>& nums, int x) {

        int sum = 0;
        for(int num: nums)
            sum += num;

        /*Problem : Lognest Subarray With Given Sum equals to target */

        int target = sum - x, ans = INT_MIN, cur = 0;
        
        // Edge Case:

        // All Elements are positive so negative sum can not be achieved. Return -1.
        if(target < 0)
            return -1;
        
        // If target is zero means that all the array is our solution because we need longest subarray.
        if(target == 0)
            return nums.size();
    
        // Keep track of <curSum, index>
        unordered_map<int,int> mp;
        mp[0] = -1;

        for(int j = 0; j < nums.size(); j++) {

            cur += nums[j];

            if(mp.count(cur - target)) {
                ans = max(ans, j - mp[cur-target]);
            }    
            mp[cur] = j;
        
        }

        // If not found any subarray return -1.
        if(ans == INT_MIN)
            return -1;
        
        // shortest subarray with size X = array.size - (longest subarray with sum = SUM(Array) - X)
        return nums.size() - ans;
    }
};