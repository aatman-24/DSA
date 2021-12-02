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

Question: 669. Trim a Binary Search Tree
Topic : Tree
Problems : https://leetcode.com/problems/trim-a-binary-search-tree/

==============================> Explanation <=============================================

- logic is that,

- If current node is safe then trim it's left and right subtree.
- Else:
    if(root -> val < low)
        Then root -> right child could be the root if it is in a range.
    if(root -> val > high)
        Then root-> left child could be the root if it is in a range.

So we perform using recursion... Before triming any node we must check either left or right child
subtree is in range or not so we apply triming first on that and then return the updated root.

==============================> Apporach and Time Complexity <=============================================

1) Tree
Time: O(N)
Space: O(N)(Aux)

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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        if(root == nullptr)
            return root;

        // If the current root is safe then trim it's left and right child.
        if(root -> val >= low && root -> val <= high) {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root -> right, low, high);
        }

        // Else either its left or right subtree, could be root.
        else if(root -> val < low) {
            root = trimBST(root -> right, low, high); 
        }
        else {
            root = trimBST(root -> left, low, high);
        }
        return root;
    }
};