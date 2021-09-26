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

Question: 1546. Maximum Number of Non-Overlapping Subarrays With Sum Equals Target
Topic : prefixSum
Problems :  https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/

==============================> Explanation <=============================================
Ideas comes from that, we already know how to get all the subarray with the target sum using prefix method.
Same is used here but our main focus is to use as many as subarray, so for that we must use smallest subarray
so overall the count is more. So we greedily find the smallest subarray once we found we set the last_limit
which is the index of the subarray ending point.

- Sliding window is possible but due to negative number it is complex to solve using that needs other priority
queue also to store the negative index which also take O(N) space, so rathar than this is best apporach.


==============================> Apporach and Time Complexity <=============================================
1) Prefix SUM:
Time: O(N)
Space: O(N) 
*/



class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {

        // <cur_sum, index>
        unordered_map<int,int> mp;

        // Initial sum is zero which is at index = -1. (This is for the starting to the i th index case).
        mp[0] = -1;

        // last_limit is the right side of subarray which is already part of the solution.
        int count = 0, last_limit = -1, curr=0;
        
        for(int i = 0; i < nums.size(); i++) {
        
            curr += nums[i];
        
            // found subarray
            if(mp.count(curr-target)) {
            
                // check overlapping or not.
                if(mp[curr-target] + 1 > last_limit) {
                    count++;
                    last_limit = i;     // set the last_limit.
                }
            }
            mp[curr] = i;
        }
        return count;
    }
};