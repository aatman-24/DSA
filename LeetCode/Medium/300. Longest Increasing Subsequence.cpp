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
Topic : Binary Search, DP
Problems : https://leetcode.com/problems/longest-increasing-subsequence/

==============================> Explanation <=============================================
Allocate Books (BS + Greedy)

this (BS + Patience Sorting)

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


1) DP: Standard Problem


1) Choise Diagram: If we are at current index i in the array. Then LIS[i] is the maximum among all,
                   numbers arr[j] such that, It can be extend all the LIS for which nums[j] < nums[i].
                   So that, reason LIS[i] = LIS[j] + 1. nums[j] < nums[i]. j can be (0 -> i).

2) Base Case: LIS[i] = 1. Every number itself is LIS.

3) Recurrence Relation: 
                    for j = 0 -> i,
                        if(nums[j] < nums[i])
                            LIS[I] = max(LIS[i], LIS[j]+1)



*/


/*
==============================> Edge Case <=============================================
1) Top-Down + Bottom-UP Linear-DP Pattern=LIS, Standard
Time: O(N^2)
Space: O(N)(Memorization)

2) Binary Search + Patience Sorting:
Time: O(NlogN)
Space: O(N)
*/

class Solution {
public:

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
                // tails[mid] indicate the number which is ending the sequence of length mid.
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

// Top-Down
class Solution {
public:

    int lengthOfLIS(int index, vector<int> &nums, int LIS[]) {

        // base case. LIS[0] = 1. Number Itself.
        if(index == 0) {
            LIS[index] = 1;
            return 1;
        }

        if(LIS[index] != -1)
            return LIS[index];

        // Number Itself is LIS.
        int maxLIS = 1;

        for(int i = 0; i < index; i++) {
            
            // ending_at_i max LIS. if nums[i] < nums[index] then LIS[index] = nums[i] + 1.
            // and we find maximum from among them.
            int ending_at_i = lengthOfLIS(i, nums, LIS);
        
            if(nums[i] < nums[index]) {
                maxLIS = max(maxLIS, ending_at_i + 1);
            }
        }

        // return the LIS ending at nums[index].
        return LIS[index] = maxLIS;
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        int LIS[n];
        memset(LIS, -1, sizeof(LIS));

        lengthOfLIS(n-1, nums, LIS);

        // LIS can be end with any element so we need to find 
        // from all of the LIS.
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, LIS[i]);
        }
            

        return ans;
    }    
};



// Bottom-up
class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        int LIS[n];

        // base case.
        LIS[0] = 1;

        for(int i = 1; i < n; i++) {

            // Number Itself.
            LIS[i] = 1;

            for(int j = 0; j < i; j++) {
            
                if(nums[j] < nums[i]) {
                    LIS[i] = max(LIS[i], LIS[j]+1);
                }
            }
        }

        // Find LIS from all the number. LIS can be end at any number.
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, LIS[i]);
        }
            

        return ans;
    }    
};