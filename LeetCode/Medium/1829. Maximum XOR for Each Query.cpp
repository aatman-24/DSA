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

Question : 1829. Maximum XOR for Each Query
Topic : XOR, Array
Problems : https://leetcode.com/problems/maximum-xor-for-each-query/
/*
==============================> Explanation <=============================================
Actullay I found the solution from the test cases.

Here given that we need to find k such that,
nums[0] XOR nums[1] XOR nums[nums.length-1] XOR k = is maximized and
k should be less than 2^maxinumBit.

0 <= nums[i] < 2^maximumBit (Is Given)
So,

2^maxinumBit - 1 result into this pattern is all 1. (1111) (11111) (111111) like this. Which is
maximum.

nums[0] XOR nums[1] XOR nums[nums.length-1] XOR k its maximized value
could be = 2^maxinumBit - 1.


So To get maximized value k can be adjust its value as per the
nums[0] XOR nums[1] XOR nums[nums.length-1].


For finding k which give the maximized value of above eqaution we need
to xor the maximized value with equation.


k = nums[0] ^ nums[1] ^ nums[nums.length-1] ^ pow(2,maxinumBit).

0101 ^ k = 1111
1101 ^ k = 1111

So k = 1111 ^ 0101 = 1010. (simple we try to make 1's at place of 0 into left side)
*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:


    // Here we take prefixXor Sum and again do the xor with integer n 
    // which is going to remove into next step so overall this element
    // xorsum is 0. (A^A = 0).

    // O(N) - O(1)
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {

        int n = nums.size();
        vector<int> ans(n,0);

        int xorSum = pow(2,maximumBit) - 1;
        for(int k : nums) {
            xorSum ^= k;
        }
        ans[0] = xorSum;

        for(int i = 0; i < n-1; i++) {
            xorSum ^= nums[n-i-1];
            ans[i+1] = xorSum;
        }

        return ans;
    }

    // Here we put the answer from the last index so don't need to
    // do prefix sum at every iteration we can do it.
    // Precise
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {

        int n = nums.size();
        vector<int> ans(n,0);

        int xorSum = pow(2,maximumBit) - 1;

        for(int i = 0; i < n; i++) {
            xorSum ^= nums[i];
            ans[n-i-1] = xorSum;
            
        }
        return ans;

    }

};