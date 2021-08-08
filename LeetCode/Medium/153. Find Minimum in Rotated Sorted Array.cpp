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

Question : 153. Find Minimum in Rotated Sorted Array  
Topic : Binary Search
Problems : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

==============================> Explanation <=============================================




Apporach 1) O(N) Linear Search.

Appoorach 2) O(logN) (binary Search)

*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:
    
    int findMin(vector<int>& arr) {

        int l = 0, h = arr.size() - 1;

        while(l < h) {

            int mid = (l + h) >> 1;


            // if arr[mid] is less than both boundary.
            if(arr[l] >= arr[mid] && arr[mid] < arr[h]) {

                int pre = (l == mid) ? arr[mid] : arr[mid-1];
                int nxt = arr[mid+1];

                // if it is less than both neighbours then it is our answer.
                if(pre >= arr[mid] && arr[mid] < nxt) {
                    return arr[mid];
                }
                // otherwise move whatever is less.
                else if(pre < arr[mid]) {
                    h = mid - 1;
                }
                else {
                    l = mid + 1;
                }

        }

        // if arr[mid] is greater than boundary move to the lesser boundary side.
        else if(arr[l] < arr[mid] && arr[mid] > arr[h]) {
            if(arr[l] < arr[h]) {
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        // Otherwise move the less boundary.
        else if(arr[l] < arr[mid]) {
            h = mid - 1;
        }

        else {
            l = mid + 1;
        }
    }

    return arr[l];
}



    // Here once things to remember is that, (mid != high) when (l + h)/ 2. but
    // mid can be low. So use this approach.

    // Standard Binary Search.
    int findMin(vector<int>& arr) {

        int l = 0, h = arr.size() - 1;

        while(l < h) {

            int mid = (l + h) >> 1;


            // we know that arr[mid] < arr[h]. means it is sorted. so 
            // we place h = mid. (because it is possible that arr[mid] is answer)
            // answer is reside on left side.
            if(arr[mid] < arr[h]) {
                h = mid;
            }
            // if arr[mid] < arr[h] is not correct. Means our answer is reside on right side.
            else {
                l = mid + 1;
            }
                    
        }

        return arr[l];
    }
};