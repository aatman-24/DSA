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

Question : 80. Remove Duplicates from Sorted Array II
Topic : Two pointer
Problems : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

==============================> Explanation <=============================================

- keep track of prev, curr and next pointer.
- prev == curr that means we already allowed two duplicate so we don't allow "next" if prev == next.
- curr != next || curr == next && (prev != next) -> next is new number.

==============================> Apporach and Time Complexity <=============================================

1) Two Pointer
Time: O(N)
Space: O(1)

*/


class Solution {

public:
    
    int removeDuplicates(vector<int>& nums) {
            
        int N = nums.size();

        if(N <= 2)
            return N;

        // point to first duplicate.
        int prev = INT_MIN;

        // point to second duplicate.
        int curr = 0;

        // find next element.
        int next = 1;

        while(next < N) {

            // (new number || (first == second duplicate found, next is new number))
            if(nums[curr] != nums[next] || (nums[curr] == nums[next] && prev != nums[next])) {
                
                curr++;
                
                // keep track of previous.
                prev = nums[curr-1];
                
                // placed new number
                nums[curr] = nums[next];
            }
            next++;
        }

        // increment by 1, because we start curr with zero.
        return curr+1;

    }
};