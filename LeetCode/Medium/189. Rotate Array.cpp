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


/*
==============================> Description <=============================================

Question: 189. Rotate Array
Topic : Array
Problems : https://leetcode.com/problems/rotate-array/

==============================> Explanation <=============================================
Here we need to made right rotation, So the N-1, N-2 element needs to swap at the start of
the array. For that reason cyclic index is needed that's why used (curr+K % N).

1) Peform what you given. Swap the array by right total K times. K = K % N.

2) First Copy the given element into the new array and using that newly created array
perform the rotation for K Step.  arr[i+k%N] = copy[i]; (placed each element of copy
to the right place into the array).

3) Keep Track Single Element(In Cycle),
-Here, We keep rotating element into the cycle. We keep track of current index(curr),
starting index of the cycle(start) and element which will be placed at the next [curr+k]
index(numsTobeRotated).
- Total swap opreation is performed N times. Because exactly N elements change its 
position.
- Start the cycle, swap(numsTobeRotated, nums[curr+k]) it means that we placed the
numsTobeRotated at right position. But whatever element is there needs to be also 
placed at right position which is performed in the next times.
- But we check that (curr != start) otherwise we overwrite already swapped element which
is right placed. When curr == start, cycle is completed and perform start++. which 
perform the same things with the next elements.

Example....

    0 1 2 3
    1 2 3 4 (k = 2) numsToBeRotated = 1

    1 2 1 4 numsToBeRotated = 3

    3 2 1 4 numsToBeRotated = 1 (Start == Curr) Start++

    3 2 1 4 numsToBeRotated = 2

    3 2 1 2 numsToBeRotated = 4

    3 4 1 2 numsToBeRotated = 2 (start == curr) but all elements visited once. Break.


1 2 3 4 5 6 7 (k = 3) Try it with yourself. In single cycle it completed.


4) Reversing the array:
- Reverse the array.
- Reverse the first k elements.
- Reverse the remaining k elements.


==============================> Apporach and Time Complexity <=============================================

1) Brute Force:
Time: O((N%K) * N)
Space: O(1)

2) Copy of array:
Time: O(N)
Space: O(N)

3) Cycle Rotation with single element:
Time: O(N)
Space: O(1)

4) Array Rotation:
Time: O(N)
Space: O(1)

*/

class Solution {
public:

    void rotate(vector<int>& nums, int k) {

        int N = nums.size();
        k = k % N;
        if(k == 0)
            return;

        vector<int> copy(nums.begin(), nums.end());
        for(int i = 0; i < N; i++) {
            nums[(i+k)%N] = copy[i];
        }
    }
};




class Solution {
public:

    void rotate(vector<int>& nums, int k) {

        int N = nums.size();
        k = k % N;
        if(k == 0)
            return;

        // Cycle starting point.
        int start = 0;

        // Jump Into the current cycle
        int curr = start;

        // Keep track of num to be placed at (curr + K) position.
        int numsTobeRotated = nums[curr];

        int totalRotation = 0;

        // Total N elements are going to be swapped.
        while(totalRotation < N) {

            // Place the numsTobeRotated at (curr + k) and new numsTobeRotated is old nums[curr+K].
            swap(numsTobeRotated, nums[(curr+k)%N]);

            // Take the Jump.
            curr = (curr+k)%N;

            totalRotation++;

            // Here you already placed the value in last step. And again come to here that
            // means it is form the cycle. And if we continue then it override the value
            // placed during the cycle.

            // So we stop and increase the start point and perform the same opreation.
            if(curr == start) {
                start++;
                curr = start;
                numsTobeRotated = nums[curr];
            }
        }
    }
};




class Solution {
public:

    void reverse(vector<int> &nums, int start, int end) {
        while(start <= end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {

        int N = nums.size();
        k = k % N;
        if(k == 0)
            return;

        // 1 2 3 4 5 6 7 , K = 3    -> 5 6 7 1 2 3 4

        reverse(nums, 0, N-1);     // -> 7 6 5 4 3 2 1
        reverse(nums, 0, k-1);     // -> 5 6 7 4 3 2 1
        reverse(nums, k, N-1);    //  -> 5 6 7 1 2 3 4
    }
};