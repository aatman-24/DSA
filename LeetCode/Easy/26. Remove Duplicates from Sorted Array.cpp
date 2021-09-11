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

*/


/*
==============================> Edge Case <=============================================



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
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