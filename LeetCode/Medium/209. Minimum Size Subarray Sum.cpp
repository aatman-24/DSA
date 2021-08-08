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

Question : 209. Minimum Size Subarray Sum
Topic : Sliding Window
Problems : https://leetcode.com/problems/minimum-size-subarray-sum/
/*
==============================> Explanation <=============================================

*/

/*
==============================> Edge Case <=============================================

*/

// Approach 1 : O(N^2) generate all subarray using two for loops. and keep track of minimum length which
// subarray sum is greater or equal to target.

// Apporach 2 : Sliding window O(N)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int begin = 0, end = 0, sum = 0, length = INT_MAX;
        while(end < nums.size()) {
            // add the end pointer into sums
            if(sum < target) sum += nums[end++];

            // if sum >= target we can shrink the window and can get minimum window so increase the begin pointer.
            while(begin <= end && sum >= target) {
                    sum -= nums[begin];
                    length = min(length, end - begin);
                    begin++;
            }
        }
        return length == INT_MAX ? 0 : length;   
    }
};