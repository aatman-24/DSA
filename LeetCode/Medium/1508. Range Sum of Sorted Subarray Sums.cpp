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

Question : 1508. Range Sum of Sorted Subarray Sums
Topic : Array, Recursion, Backtracking
Problems : https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/
*/

class Solution {
public:
   
   // O(n^2*log(n^2))
    int rangeSum(vi nums, int n, int left, int right) {
        vector<int> sums;
        for (int i = 0; i < n; i++) {
            int prefixSum = 0;
            for (int j = i; j < n; j++) {
                prefixSum += nums[j];
                sums.push_back(prefixSum);
            }
        }

        sort(sums.begin(), sums.end());

        int res = accumulate(sums.begin()+left-1, sums.begin()+right, 0LL) % mod;
        return res;

    }


};