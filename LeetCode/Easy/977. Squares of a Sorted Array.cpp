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

Question: 977. Squares of a Sorted Array
Topic : Sorted Array
Problems : https://leetcode.com/problems/squares-of-a-sorted-array/

==============================> Explanation <=============================================

- Idea is that, We divide the array into negative and positive numbers.
- After compare which one is smallest(without sign), we add that numbers first into answer.


Edge Case:

1) Both Pos and Negative present:

-4,-1, | 0,3,10  -> Neg = 1, Pos = 2

2) Only Negative present:

-4 -3 -2 -1  -> neg = 3, pos = 4

3) Only Positive Present:

1 2 3 4 5 -> Neg = -1, pos = 0.

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern = Cadane
Time: O(N)
Space: O(1)

*/




class Solution {

public:

    vector<int> sortedSquares(vector<int>& nums) {
            
        // pos - points to zero or positive number(right side of array).
        int pos = 0, n = nums.size();

        while(pos < n && nums[pos] < 0) pos++;

        // neg - points to negative number(left side of array).
        int neg = pos - 1;

        vector<int> ans;

        while(neg >= 0 && pos < n) {

            // Compare Without Sign.
            if(abs(nums[neg]) <= nums[pos]) {
                ans.push_back(nums[neg] * nums[neg]);
                neg--;
            }
            else {
                ans.push_back(nums[pos] * nums[pos]);
                pos++;
            }   
        }


        // Remaining elements.
        while(neg >= 0) {
            ans.push_back(nums[neg] * nums[neg]);
            neg--;
        }

        while(pos < n) {
            ans.push_back(nums[pos] * nums[pos]);
            pos++;
        }

        return ans;

    }
};