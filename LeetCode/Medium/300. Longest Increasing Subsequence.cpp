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

Question :  300. Longest Increasing Subsequence
Topic : Binary Search
Problems : https://leetcode.com/problems/longest-increasing-subsequence/

==============================> Explanation <=============================================
Allocate Books (BS + Greedy)

this (BS + Patience Sorting)


1) DP -> O(N^2) + O(1)
2) Binary Search -> O(NlogN) + O(N)

How to find LIS using Binary Search? (Intersting! Isn't it ?)

- First Refer to this Article.
https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

Conclusion of this article:

- Suppose we have many Increasing subsequence right now. Suppose the next element is 
A[i]. So Where we placed A[i] ?


Rule 1:
- If A[i] is smallest among all the Sequence last end element. Start New Sequence
with A[i] of length 1.

Rule 2:
- If A[i] is greater than all the sequence end element, extend the largest 
sequence by A[i].

Rule 3:
- If A[i] is between smallest and greater, Find the sequence with the largest end
element which is smaller than A[i], extend the sequence by adding A[i]. And eliminate
all the sequence of same length.
(In short) -> if A[i] is less than, X end element replace X with A[i] into the list.


Okay So how binary Search apply ?

https://leetcode.com/problems/longest-increasing-subsequence/discuss/74824/JavaPython-Binary-search-O(nlogn)-time-with-explanation


- The end element of any sequence is increasing monotonic function. So we use the
binary search to find the right place for the Current A[i] which is 
the currently largest element of largest sequence. (just like upper bound)


- we store the end element of sequence of ith length. For that we use another array.

- Read about Patience sorting.
https://en.wikipedia.org/wiki/Patience_sorting
https://www.cs.princeton.edu/courses/archive/spring13/cos423/lectures/LongestIncreasingSubsequence.pdf


Time -> O(NlogN)



*/


/*
==============================> Edge Case <=============================================

*/

class Solution {
public:

    // DP - Edit Distance (LIS Standard).

    // Binary Search -> O(NlogN) + O(N)

    int lengthOfLIS(vector<int>& nums) {

        vector<int> tails(nums.size(), 0);
        int size = 0;

        for(int num: nums) {

            // apply binary search to find the right place.


            int l = 0, h = size;
            while(l < h) {
                int mid = (l + h) >> 1;

                // we need to find largest number than tails[mid].
                if(tails[mid] < num) {
                    l = mid + 1;
                }
                // Need to find the large number which is smaller. Already we have
                // tails[mid] but still we need to find smaller than num if we can.
                else {
                    h = mid;
                }
            }
            // put at right place.
            tails[l] = num;
            if(l == size) size++;
        }

        return size;
    }
    
};