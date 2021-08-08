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

Question :  108. Convert Sorted Array to Binary Search Tree
Topic : Tree
Problems : 108. Convert Sorted Array to Binary Search Tree

==============================> Explanation <=============================================
Choose the middle element always as current node. It always return height-balanced binary search tree.
*/


/*
==============================> Edge Case <=============================================

*/


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

    TreeNode* helper(vector<int> &nums, int start, int end) {

        if(start > end)
            return NULL;

        int mid = (start + end) >> 1;

        TreeNode* curr = new TreeNode(nums[mid]);
        curr -> left = helper(nums, start, mid-1);
        curr -> right = helper(nums, mid+1, end);

        return curr;
    }


    // O(N) - O(1).
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};