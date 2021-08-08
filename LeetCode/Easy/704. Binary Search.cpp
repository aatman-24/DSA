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

Question : 704. Binary Search
Topic : Binary Search
Problems : https://leetcode.com/problems/binary-search/

==============================> Explanation <=============================================
Standard Binary Search.

*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:

    // Binary Search - O(logN)
    int search(vector<int>& nums, int target) {

        int low = 0, high = nums.size() - 1;

        while(low <= high) {

            int mid = (low + high) / 2;

            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return -1;
    }
};