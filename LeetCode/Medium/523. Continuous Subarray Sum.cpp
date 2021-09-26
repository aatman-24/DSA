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

Question: 523. Continuous Subarray Sum
Topic : prefixSum, Mod
Problems : https://leetcode.com/problems/continuous-subarray-sum/

==============================> Explanation <=============================================
- In Short Intuition behind the algorithm,
--> we keep track of (cursum % K) and put into the map. If any time (curSum % K) value is repeated it 
means that, from (i, j] is multiple of K.
--> Why? Repeating the value of (curSum % K) means that it completed the cycle at jth index again which length is n * K. (n is any value > 0)
--> And Edge case is that if we find (curSum % K) == zero it means that from (0, j] subarray sum is multiple of K.


Math Intuition:

[x1, x2, x3, x4, x5] is element of the array with index starting from the 1.
- Now if at second index currentSum is a, and at 4th index currsentSum is b.
b - a = d--------------(1) (a <= b) && d is multiple of k, then d % k = 0,
b = a + d
b % k = (a % k + d % k) % k (For satisfying this equation d % K must be zero)
b % k = (a % k + 0) % k (now again satisfying this a % k == b % k)
b % k = a % k ------------ (2)


Other Intuition:

Suppose sum_i represents the running sum starting from index 0 and ending at i,
once we find a mod that has been seen, say modk, we have:
current one: sum_i = m*k + modk
previous one: sum_j = n*k + modk
Thus,
sum_i - sum_j = (m - n) * k 


Single Equation Proof:

- (a+(n*k))%k is same as (a%k)


mod property:
- In array if curSum%K is repeated then both occurance subarray sum is multiple of K.

==============================> Apporach and Time Complexity <=============================================
1) BruteForce: (i and j create subarray, k for (i, j) sum)
Time:O(N^3)
Space:O(1)

2) Prefix Sum:
Time: O(N)(PrefixSum) + O(N^2)(Get all subarray Sum)
Space: O(1)

3) Prefix Sum with Mod Opreation:
Time:O(N)
Space:O(K)

*/


class Solution {
public:

    bool checkSubarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        // Base Case, (0, j] subarray sum is multiple of K. (j is the index where curSum%K == 0)
        mp[0] = -1;

        int curSumMod = 0;

        for(int i = 0; i < nums.size(); i++) {

            int num = nums[i];

            curSumMod = (curSumMod + num) % k;

            // Second Time Happen.
            if(mp.count(curSumMod)) {

                // Check Length of SubarraySum.
                if(i - mp[curSumMod] > 1) {
                    return true;
                }
            }
            else
                mp[curSumMod] = i;
        }
        return false;
    }
};