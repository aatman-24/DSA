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

Question : 162. Find Peak Element
Topic : Binary Search
Problems :https://leetcode.com/problems/find-peak-element/

==============================> Explanation <=============================================

*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:

    // 1) Brute force: find the Greatest element from the array. Which is peak element. So it 
    // is O(N).  

    // // 2) Binary Search : O(logN)
    // - Array is not sorted then also using binary search we can find peak element. Reason 
    // is that full array is not sorted but some of it parts is sorted. That's why we use 
    // this logic to find max element. 

    //   P   
    //  / \  (Left side is small) (peak) (right side is small). So we using the 
    // arr[mid] and next element we can decide which side should be shrink ?

    // if arr[mid] < arr[mid+1] (shrink the left side) l = mid+1
    // arr[mid] > arr[mid+1] (shrink the right side)   h = mid

    int findPeakElement(vector<int>& nums) {

        int l = 0, h = nums.size() - 1;
        while(l < h) {

            int mid = (l + h) >> 1;
            int mid2 = mid + 1;

            if(nums[mid] < nums[mid2]) {
                l = mid2;
            }
            else {
                 h = mid;
            }
        }

        return l;

    }
};