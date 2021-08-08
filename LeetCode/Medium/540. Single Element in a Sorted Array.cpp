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

Question : 540. Single Element in a Sorted Array
Topic : Binary Search 
Problems : https://leetcode.com/problems/single-element-in-a-sorted-array/
*/

    0  1   2  3  4  5  6  7  7
    1  1   2| 3  3  4  4  5  5 
    E  O            O  E 

See the observation,

In first part where our solution is lie (2),

    first occurance -> Even Index. 
    Second occurance -> Odd Index. 

Second part,

    first occurance -> Odd Index. 
    Second occurance -> Even Index. 

We used this therory. 


How ?

We only use one of these not need to check for both. Suppose we track odd index so 
when the even index found perform mid++. If we track of even index then odd index found 
perform mid--.

I tracked the odd index.   

So if mid is even make it odd. by mid++.  

    if(nums[mid] == nums[mid+1]) then we are in second part. So make the high = mid - 1.   
    else we are in first part make the low = mid + 1.  


this run until the low < high.  and you found that our solution is at low index.




/*

Edge Case: 

*/



class Solution {
public:

    // Brute force is = O(N), O(1)
    // Same element XOR Become zero. So Xor all element last whatever is answer.

    // Optimized apporach is Binary Search.

    // I coded by observation it is also binary search.
    int singleNonDuplicate(vector<int>& arr) {

        int l = 0, r = arr.size() - 1;

        while(l <= r) {

            if(l == r) return arr[l];

            int mid = (l+r)/2;

            if(mid % 2 == 0) {
                if(arr[mid-1] == arr[mid]) {
                    r = mid;
                }
                else {
                    l = mid;
                }
            }
            else {
                if(arr[mid-1] == arr[mid]) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;    
                }
            }
        }
        return -1; // never excuted.
    }


    // Precise By Striver. Interview ready question.
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, h = nums.size()-1;

        while(l < h) {

            int mid = (l + h) >> 1;

            // If it is even make it odd.
            if(mid % 2 == 0) mid++;

            // for the second part mid is first occurance of any element. So if if
            // is then we need to find our answer into the first part means left side.
            // so high = mid - 1.
            if(nums[mid] == nums[mid+1]) {
                h = mid - 1;
            }
            else {

                // Here is oppsite of above. make it low = mid + 1 if first condition is 
                // false because we are at the second occurace of element which is wrong.
                // so we will find our solution on right.
                l = mid + 1;
            }
        }

        return nums[l];
    }


    // Very Intersting Solution which contain both the condition even and odd index.
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, h = nums.size()-1;

        while(l < h) {

            int mid = (l + h) >> 1;
            // mid ^ 1 return,
                // if mid is odd -> It return the previous even. mid = 3, mid^1 = 2.
                // mid is even -> It return the next odd number. mid = 2, mid^1 = 3.
            // so here both condition is combine into the one. And only check if both 
            // elements either previous or next is same. If is same the move the low = mid + 1
            // either h = mid - 1. (Vice versa with above solution). Check striver video if
            // don't make sense

            if(nums[mid] == nums[mid^1]) {
                
                l = mid + 1;
            }
            else {

                h = mid - 1;
            }
        }

        return nums[l];
    }
};



