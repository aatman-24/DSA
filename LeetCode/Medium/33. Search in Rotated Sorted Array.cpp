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

Question : 33. Search in Rotated Sorted Array
Topic : Binary Search
Problems : https://leetcode.com/problems/search-in-rotated-sorted-array/

==============================> Explanation <=============================================
Intution -> Sorted Array. Can be apply binary search.

Given array is sorted but rotated. Then how to apply binary search ?

Binary Search, we know that, arr[low] <= arr[mid] <= arr[high].

Okay, 

            4(l) 5 6 7(m) 0 1 2(h)  target = 0.

- So We first check which part is sorted [l, m] or [m, h]. Because binary search only
be apply to the sorted parts.

here, [4, 7] is sorted.  arr[l] <= arr[mid].
    
    - then check if target is into this range. If yes then and only we move to this
      side otherwise remaining side(right).

    but no it is not.  so we make,

        4 5 6 7 0(l) 1(m) 2(h)  target = 0. (regular binary search)

Test case:

        5(l) 6 7 1(m) 2 3 4     target = 2

    - so here left part is not sorted. So it is obvisouly right part is sorted. 
    We check on that if we our element into this range we move to right other wise left.

    How to check. ?

            arr[mid] <= target &&  target <= arr[h] (checking right side)

                 if yes move to this range by, l = mid + 1

            else 

                move the left side. h = mid - 1.



In short, 

    We first find which part is sorted [l, m] or [m, h]. Once we find that 

        which ever is sorted on this part only we check that our target beside on it
        or not. If yes then move to the sorted part else move to the unsorted part.
*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:

    // Naive approach - Linear Search, O(N) - 1



    // O(NLogN) - O(1)
    int search(vector<int>& arr, int target) {

        int l = 0, h = arr.size() - 1;

        while(l <= h) {

            int mid = (l + h) >> 1;

            if(arr[mid] == target) return mid;

            // sorted parts is from [left, mid].
            if(arr[l] <= arr[mid]) {

                // target in sorted part.
                if(target >= arr[l] && target <= arr[mid]) {
                    h = mid - 1;
                }

                // target is in unsorted part.
                else {
                    l = mid + 1;
                }
            }

            // sorted parts id [mid, high]
            else {

                // target is in sorted part.
                if(target <= arr[h] && target >= arr[mid]) {
                    l = mid + 1;
                }

                // target is into unsorted part.
                else {
                    h = mid - 1;
                }
            }

            
        }
        return -1;
    }
};