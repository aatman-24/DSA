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

Question : 26. Remove Duplicates from Sorted Array
Topic : Array
Problems : https://leetcode.com/problems/remove-duplicates-from-sorted-array/

==============================> Explanation <=============================================
1) Brute Force: Intuition from the Insertion sort algorithm, at ith index not duplicated element was last then,
at we are at jth index if arr[i] != arr[j] then, arr[j] is next after the arr[i], so start from the jth index
and swap until arr[i]. just like insertion algorithm.

2) Two Pointer: Sorted array all duplicate number are together so just using two pointer only the
non-duplicate number needs to swap. At the end of array is not matter what it is.

==============================> Apporach and Time Complexity <=============================================
1) Brute Force:
Time: O(N^2)
Space: O(1)

2) Two Pointer:
Time: O(N)
Space: O(1)

*/



class Solution {
public:

    // Brute force: O(N^2)
    // Keeping the tail element as it is. 
    int removeDuplicates(vector<int>& nums) {

        if(nums.size() <= 1) return nums.size();

        int i = 0, j = i + 1;

        while(j < nums.size()) {

            // Both element not same then jth element must be next after ith element.
            // So move jth element after ith element by swapping all other element between i and jth.
            if(nums[i] != nums[j]) {
                
                int k = j;
                int number = nums[j];

                // jth must be stop after ith position.
                while(i+1 != k) {
                    nums[k] = nums[k-1];
                    k--;
                }

                nums[k] = number;
                i++;
            }

            j++;
        }

        return i+1;
    }



    // but here given that in tail(duplicate element) which element is present after it
    // does not matter. So we can use this condition to make it more robust.
    // O(N) - O(1)
    int removeDuplicates(vector<int>& nums) {

        if(nums.size() <= 1) return nums.size();

        int i = 0, j = i + 1;

        while(j < nums.size()) {

            // just replace (i+1)th element with next non duplicate jth number. No need to
            // swap duplicate elements.
            if(nums[i] != nums[j]) {
                nums[i+1] = nums[j];
                i++;
            }
            j++;
        }

        return i+1;
    }
};