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

Question: 1590. Make Sum Divisible by P
Topic : prefixSum, ModMultiplication
Problems :  https://leetcode.com/problems/make-sum-divisible-by-p/

==============================> Explanation <=============================================
- Intuition is that, 
- We perform the sum(arr) % P... whatever is result is the sum which we try to remove from the arr so that
it is % P of it gives ZERO means it is divide by P.

Why % P ? -> Division, Multiplication always comes with %. 
Because it,
A % P = B % P -> from (A(i), B(j)) is divisble by P.


sum(arr) % P -> Gives the extra sum which is actually the (subarray_sum % p) which we try to remove.

Then this problem is converted into,

Find the smallest subarray whose (sum % p) is equal to target.

- And number is negative also so that reason we have to make sure that curSum > 0 while performing the MOD.

==============================> Apporach and Time Complexity <=============================================

1) Prefix sum in Division:
Time: O(N)
Space: O(N) 

*/




class Solution {
    
public:

    int minSubarray(vector<int>& nums, int p) {

        int curSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            curSum = (curSum + nums[i]) % p;
        }

        // No subarray need to remove.
        if(curSum == 0)
            return 0;


        // Find the smallest subarray whose sum is equal to target(curSum).
        unordered_map<int,int> mp;
        mp[0] = -1;

        int ans = INT_MAX, target = curSum, curr=0;

        for(int i = 0; i < nums.size(); i++) {

            curr = (curr + nums[i]) % p;
            
            // When the (curr-target) is negative make it positive then take the modulo of P.
            int want = (curr - target + p) % p;
            
            if(mp.count(want)) {

                // (mp[want]+1, i)
                ans = min(ans, i - mp[want]);
            }
            
            mp[curr] = i;
        }
        
        return ans >= nums.size() ? -1 : ans;

    }
};