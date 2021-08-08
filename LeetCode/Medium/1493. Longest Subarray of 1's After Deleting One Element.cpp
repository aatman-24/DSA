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

Question : 1493. Longest Subarray of 1's After Deleting One Element
Topic : Sliding Window
Problems : https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
/*
==============================> Explanation <=============================================

*/

/*
==============================> Edge Case <=============================================

*/

// 


class Solution {
public:


    // Shrinkable sliding window O(N)
    int longestSubarray(vector<int>& nums) {

        int n = nums.size();
        int l = 0, r = 0, res = 0, count = 0;

        while(r < n) {

            count += nums[r++] == 0;
            while(count > 1) {
                count -= nums[l++] == 0;
            }
            res = max(res, r - l);

        }
        return res-1; // -1 must delete one element from the array no matter it is 0 or 1.
    }


    // Non-shrinkable sliding window

    int longestSubarray(vector<int>& nums) {

        int n = nums.size();
        int l = 0, r = 0, count = 0;

        while(r < n) {
            count += nums[r++] == 0;
            if(count > 1) count -= nums[l++] == 0;
        }

        return r-l-1; // -1 must delete one element from the array no matter it is 0 or 1.

    }
};