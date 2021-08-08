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

Question : 81. Search in Rotated Sorted Array II    
Topic : Binary Search
Problems : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

==============================> Explanation <=============================================

- 33. Search in Rotated Sorted Array (Same Question but here given that duplicate is
also allow).

- How to deal with duplicate when searching? Is it even same algorithm ?

-->> No, We have to deal with duplicate. Algorithm is simple, we find the mid and
our next search space is based on which part is sorted and sorted part contain the
target or not.

-> but when the duplicate is allowed that time we can not take the decision.

    1 0 1 1 1 (mid = 1, low = 1, high = 1)

    arr[low] <= arr[mid]
        arr[low] < target && target < arr[mid] (Based on this condition we traverse the left)
            Left side
        else:
            right side


- but we need to move the left but algorithm is forcing us to go right which result in
wrong answer.


- Reason behind is that we are not supposed to take decision but still we are taking the
  decision.

  when  (arr[low] == arr[mid] == arr[high]) we can not take the any decision which side
    should be shrink or which not.

    1 0 1 1 1
    1 1 1 0 1

- That time we shrink the low and high to make the space decisionable.

    0 1 1 (go left)
    1 1 0  (go right)

    Now we can take the decision.  


- so in worst case it may take O(N). Otherwise O(NlogN).


Apporach 1) O(N) Linear Search.

Appoorach 2) Average Case = O(logN) (binary Search), Worst case = O(N) 

*/


/*
==============================> Edge Case <=============================================


*/

class Solution {

public:
  
    bool search(vector<int>& arr, int target) {

        int l = 0, h = arr.size() - 1;
        
        while(l <= h) {

            int mid = (l + h) >> 1;

            if(arr[mid] == target) return true;

            // the only difference from the first one, trickly case, just updat left and right
            if((arr[l] == arr[mid]) && (arr[h] == arr[mid]) ) {++l; --h;}


            else if(arr[l] <= arr[mid]) {

                if(arr[l] <= target && target < arr[mid]) {
                    h = mid - 1;
                }
                else {
                    l = mid + 1;
                }

            }
            else {

                if(arr[mid] < target && target <= arr[h]) {
                    l = mid + 1;
                }
                else {
                    h = mid - 1;
                }
            }
        }

        return false;
    }


};