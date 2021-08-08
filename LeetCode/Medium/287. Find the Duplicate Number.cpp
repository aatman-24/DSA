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

Question : 287. Find the Duplicate Number
Topic : Two pointer
Problems : https://leetcode.com/problems/container-with-most-water/
*/


class Solution {
    public:

    // O(N^2) - O(1) Individual check for all element.
    // O(NlogN) - O(1) Sort and check nearby element.
    // O(N) - O(N) Keep track of count array.

    // O(N) - O(1) Floyd Cycle detection. Same as LinkedList.
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);
        
        fast = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};