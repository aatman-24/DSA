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

Question: 448. Find All Numbers Disappeared in an Array
Topic : Array, Logic
Problems : https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

==============================> Explanation <=============================================

- Logic is that,

We take the given array and make the number negative at each index... all the index where number > 0
are missing one.

Try on pen and papper.

==============================> Apporach and Time Complexity <=============================================

1) Array, Logic
Time: O(N)
Space: O(1)

*/


class Solution {

public:

    vector<int> findDisappearedNumbers(vector<int>& nums) {
     
        // Make the number at each index.
        for(int i = 0; i < nums.size(); i++) {
            nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
        }

        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                ans.push_back(i+1);
            }
        }

        return ans;
    }
};