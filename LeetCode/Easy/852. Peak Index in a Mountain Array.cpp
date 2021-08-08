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

Question : 852. Peak Index in a Mountain Array
Topic : Binary Search
Problems : https://leetcode.com/problems/peak-index-in-a-mountain-array/

==============================> Explanation <=============================================

How binary Search ?
- Here Using binary search we found that arr[mid] < arr[mid+1]. 
    If yes,

        [low,high] = [mid+1, high]. We already go arr[mid] < arr[mid+1] (Left Boundary means left downside)
    else,
        [low, high] = [low,  mid-1], We got right downword.

We do until the low < high. (means at starting either we follow left downside or right downside). Algorithm
say you need to follow that, but you don't follow means you got opposite value. Which is at last.

[0, 1, 2, 0]


so at last your range is [0, 1] -> [1(low, high)] -> [low = 2, high = 1].


do on pen and paper.

*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        for(int i = 1; i < arr.size() - 1; i++) {
            if( arr[i-1] <  arr[i] &&  arr[i] > arr[i+1])
                return i;
        }
        return -1;
    }



    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size()-1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] < arr[mid+1])
                low = mid+1;
            else
                high = mid-1;
        }

        // low is mid+1 at last step.
        return low;
    }
};


