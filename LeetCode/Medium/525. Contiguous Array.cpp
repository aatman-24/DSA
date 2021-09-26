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

Question: 525. Contiguous Array
Topic : prefixSum
Problems : https://leetcode.com/problems/contiguous-array/

==============================> Explanation <=============================================
- Ideas from the subarray sum with prefix,
We add the 1 when it is 1 and we subtract 1 when it is zero. So when cursum is repeated that means there is
cycle which add something and again subtract same amount.

Example,

0 1 1(1)| 1 0 1 0(1) | 1 0 1 1 1
you can see here both cursum = 1 is repeated, so between (i, j) is same amount of 1 and 0.

==============================> Apporach and Time Complexity <=============================================
1) BruteForce: (i and j create subarray, k for (i, j) checking)
Time:O(N^3)
Space:O(1)

2) Prefix Sum:
Time: O(N)(PrefixSum) + O(N^2)(Get all subarray Sum)
Space: O(1)

3) Prefix Sum with 1 and -1:
Time:O(N)
Space:O(1)

*/


class Solution {
    
public:

       int findMaxLength(vector<int>& nums) {

        int sum = 0, ans = 0;
        unordered_map<int,int> mp;

        // At starting the sum is 0 at index -1.
        mp[0] = -1;

        for(int i = 0; i < nums.size(); i++) {
        
            if(nums[i] == 0)
                sum--;
            else
                sum++;
            
            // If the same sum is found again it means that cycle is formed between (i, mp[sum]) of the same
            // number of 1 and 0 tha's why it is reappering.
            if(mp.count(sum)) { 
                ans = max(ans, i - mp[sum]);
            }
            else {

                // Here we only first time make entry into the mp. We are finding longest that's why we don't
                // update new I.
                mp[sum] = i;
            }
        }

        return ans;
    }
};