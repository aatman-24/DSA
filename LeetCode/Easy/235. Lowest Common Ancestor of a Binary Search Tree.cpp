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

Question : 235. Lowest Common Ancestor of a Binary Search Tree
Topic : BST
Problems : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
==============================> Explanation <=============================================


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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:


    // O(N) - O(1)
    // Just like Binary Tree.
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q)
            return root;
        
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);
        
        if(!left)
            return right;
        
        else if(!right)
            return left;
        
        return root;
    }


    // O(logN) - O(1)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == nullptr || root == p || root == q)
            return root;

        if(p -> val > q -> val) {
            TreeNode* tmp = p;
            p = q;
            q = tmp;
        }

        // left child contain one value and right child contain one value means our current root is
        /// Ancestor.
        if(p -> val < root->val  && root->val < q->val)
            return root;

        // Otherewise both p and q are same side so explore it only.
        if(p -> val < root->val)
            return lowestCommonAncestor(root->left, p, q);

        return lowestCommonAncestor(root->right, p, q);
    }
};


