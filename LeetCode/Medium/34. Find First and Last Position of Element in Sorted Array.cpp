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
d
/*
==============================> Description <=============================================

Question : 34. Find First and Last Position of Element in Sorted Array
Topic : Binary Search
Problems : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

==============================> Explanation <=============================================
Idea is very clear that after looking the problem, 

lower_bound -> Points to the element or location which is less than target or first occurace of
target what we find.

upper_bound -> Points to the element which is just greater than target it never points to
the element. (so need to perform the idx--).

So using this we can find our solution, but using this need to beware about it points 
to the location which is not into the given array.


like, [2,3] target = 4 then both lower_bound and upper_bound points after the 3. means idx = 2.

So handle this case.

But I want to implement both lower_bound and upper_bound by myself. 

Here lowerBound and upperBound is same with c++ STL.

*/


/*
==============================> Edge Case <=============================================
1) Linear Search:  
Time: O(N)
Space: O(1)

2) Binary Search
Time: O(logN)(Two Times)
Space: O(1)

*/

class Solution {
public:


    int lowerBound(vector<int> &arr, int target) {

        int l = 0, h = arr.size() - 1;

        while(l <= h) {

            int mid = (l + h) >> 1;

            // we don't add arr[mid] == target because we need to find it first 
            // occurance so we need to check again in left side more that's why we 
            // change the h = mid - 1. 
            if(arr[mid] < target) {
                l = mid + 1;
            }
            else {
                h =  mid - 1;
            }
        }
        return l;
    }

    
    
    int upperBound(vector<int> &arr, int target) {

        int l = 0, h = arr.size() - 1;

        while(l <= h) {

            int mid = (l + h) >> 1;

            if(arr[mid] <= target) {
                l = mid + 1;
            }
            else {
                h =  mid - 1;
            }
        }
        return l;
    }


    
    
    vector<int> searchRange(vector<int>& nums, int target) {


        // int low = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        // int high = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        // high--;
        
        int low = lowerBound(nums, target);
        int high = upperBound(nums, target);
        high--;

        if(low >= 0 && low < nums.size() && high < nums.size() && nums[low] == target && nums[high] == target){
            return {low, high};
        }
        else {
            return {-1, -1};
        }

    }
};