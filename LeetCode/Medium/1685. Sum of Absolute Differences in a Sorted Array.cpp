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

Question : 1685. Sum of Absolute Differences in a Sorted Array
Topic : prefixSum
Problems : https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
*/



class Solution {
public:

    // O(N) - O(N)
    vector<int> getSumAbsoluteDifferences(vector<int> nums) {

        int n = nums.size();
        int pre[n], suf[n];
        int sum;
        vector<int> ans(n,0);

        sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            pre[i] = sum;
        }

        sum = 0;
        for(int i = n-1; i >= 0; i--) {
            sum += nums[i];
            suf[i] = sum;
        }

        for(int i = 0; i < n; i++) {

            if(i > 0) {
                ans[i] += abs(pre[i-1] - nums[i] * i);
            }

            if(i < n-1) {
                ans[i] += abs(suf[i+1] - nums[i] * (n-i+1));
            }

        }

        return ans;
    }



    // O(N) - O(1)
   vector<int> getSumAbsoluteDifferences(vector<int> nums) {
        int n = nums.size();
        int left = 0, right = 0;

        for(auto num : nums) right += num;

        vector<int> ans(n,0);

        for(int i = 0; i < n; i++) {

            right -= nums[i];

            if(i > 0) {
                ans[i] += abs(left - nums[i] * i);
            }

            if(i < n-1) {
                ans[i] += abs(right - nums[i] * (n-i-1));
            }

            left += nums[i];

        }
    return ans;
    }
};