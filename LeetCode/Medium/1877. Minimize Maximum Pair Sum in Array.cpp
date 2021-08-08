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

Question : 1877. Minimize Maximum Pair Sum in Array
Topic : Sort, Greedy
Problems : https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================
Greedy + sort

-> taking max + min after sorting is the minimum sum can we got.
and we take maximum of that.


1 2 3 4 5
(1 + 5) 
(2 + 3) ... is the minimum sum. and taking maximum of it
we achieve minimize the maximum pair sum.

*/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size()/2; i++) {
            ans = max(ans, nums[i] + nums[nums.size() - i - 1]);
        }
        return ans;
    }
};