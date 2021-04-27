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

Question : 238. Product of Array Except Self
Topic : Array, prefix, suffix
Problems : https://leetcode.com/problems/product-of-array-except-self/
*/


class Solution {
public:

    // O(N) - O(N).
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vi prefix(n,0); vi suffix(n,0);

        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];

        for(int i = 1; i < n; i++) prefix[i] = (nums[i] * prefix[i-1]);
        for(int i = n - 2; i >= 0; i--) suffix[i] = (suffix[i+1] * nums[i])


        vi ans(n,0);
        for(int i = 0; i < n; i++) {
            if(i == 0) ans[i] = suffix[i+1];
            else if (i == n - 1) ans[i] = prefix[i-1];
            else ans[i] = prefix[i-1] * suffix[i+1];
        }

        return ans;        
    }

    // O(N) - O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int suffixSum = 1, prefixSum = 1;
        int n = nums.size();


        for(int i = 1; i < n; i++) {
            prefixSum *= nums[i-1];
            ans[i] *= prefixSum;
        }

        for(int i = n - 2; i > -1; i--) {
            suffixSum *= nums[i+1];
            ans[i] *= suffixSum;
        }

        return ans;

    }
};