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

Question: 961. N-Repeated Element in Size 2N Array
Topic : Logic
Problems : https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

==============================> Explanation <=============================================

- O(N) - O(N), Using Hashing....

But We need O(N) - O(1).

The idea is that, if there are 2N elements and N of them are duplicates, then we can compare the three terms
together and if any of them are equals we return it.


Edge Case: [x, y, z, x] || [x, x, y, z] we start with index = 2. 

==============================> Apporach and Time Complexity <=============================================

1) Two Logic
Time: O(N)
Space: O(1)

*/


class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        for(int i = 2; i < nums.size(); i++) {
            if(nums[i-1] == nums[i] || nums[i-2] == nums[i])
                return nums[i];
        }      
        return nums[0];
    }
};