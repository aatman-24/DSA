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

Question :  105. Construct Binary Tree from Preorder and Inorder Traversal
Topic : Tree
Problems : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

==============================> Explanation <=============================================
Same. Follow up - 102. Binary Tree Level Order Traversal.

Reverse the result.

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

    int findIndexOfElement(vector<int> &arr, int low, int high, int target) {

        for(int i = low; i <= high; i++) {
            if(arr[i] == target)
                return i;
        }
        return -1;
    }


    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int low, int high, int &index) {

        if(low > high) {
            return NULL;
        }

        int ele = preorder[index++];

        int elementAt = findIndexOfElement(inorder, low, high, ele);

        TreeNode* left = helper(preorder, inorder, low, elementAt-1, index);
        TreeNode* right = helper(preorder, inorder, elementAt+1, high, index);

        TreeNode* curr = new TreeNode(ele);
        curr -> left = left;
        curr -> right = right;

        return curr;
    }


    // O(N^2) - O(1)
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return helper(preorder, inorder, 0, inorder.size()-1, index);
    }
};