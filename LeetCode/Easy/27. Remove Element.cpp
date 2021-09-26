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

Question : 27. Remove Element
Topic : Array
Problems : https://leetcode.com/problems/remove-duplicates-from-sorted-array/

==============================> Explanation <=============================================

Parent: 26. Remove Duplicates from Sorted Array

1) Brute Force: Using Two for loops. First Indicate ith index where you should add the next element and second
one is identify the correct element to be placed there.

2) Two Pointer: One pointer tell that where to place the next element and and one pointer is which element should
be placed or which not(val).

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

    int removeElement(vector<int>& nums, int val) {

        // At (val_index+1) to put the next value.
        int val_index = -1; 
        int j = 0;

        // Keep count of occurance of val.
        int count = 0;

        while(j < nums.size()) {

            // Two Pointer (val_index is indicate where to put the element)
            if(nums[j] == val && val_index == -1) {
                val_index = j;
            }

            if(nums[j] == val)
                count++;

            if(nums[j] != val && val_index >= 0) {
                nums[val_index] = nums[j];
                val_index++;
            }

            j++;
        }

        return nums.size() - count;
    }



    // Go for this not above. 
    int removeElement(int A[], int n, int elem) {
        
        int begin=0;

        for(int i=0;i<n;i++) 
            if(A[i]!=elem) 
                A[begin++]=A[i];
            
        return begin;
    }
};