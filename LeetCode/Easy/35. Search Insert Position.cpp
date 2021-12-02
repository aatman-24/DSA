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

Question: 35. Search Insert Position
Topic : Binary Search
Problems : https://leetcode.com/problems/search-insert-position/

==============================> Explanation <=============================================

- Find the lowerBound of given nums and target... I checked using pen and paper that last missing elements is pointed by 
the low or high pointer and found that it is low pointer so return it.

==============================> Apporach and Time Complexity <=============================================

1) Binary Search
Time: O(logN)
Space: O(1)

*/

class Solution {
public:

    int lowerBound(vector<int> &nums, int target) {

        int low = 0, high = nums.size() - 1;

        while(low <= high) {

            int mid = (low + high) >> 1;

            if(nums[mid] == target)
                return mid;

            if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }


        return low;
    }



    int searchInsert(vector<int>& nums, int target) {

        return  lowerBound(nums, target);

    }
};