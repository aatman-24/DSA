#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

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

Question : 94. Binary Tree Inorder Traversal
Topic : Tree
Problems : https://leetcode.com/problems/binary-tree-inorder-traversal/

==============================> Edge Case <=============================================
- Recursive.
- Morris Inorder Tree Traversal.

==============================> Explanation <=============================================

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
    
    void inorder(TreeNode* root, vector<int> &ans) {
        if(root == NULL)
            return;
        inorder(root -> left, ans);
        ans.push_back(root -> val);
        inorder(root -> right, ans);
            
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};


// Morris Inorder traversal.
class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;

        TreeNode* node = root;

        while(node != nullptr) {

            if(node->left == nullptr) {
                 ans.push_back(node->val);
                node = node -> right;
            }
            else {
                
                TreeNode* temp = node -> left;
                
                while(temp->right != nullptr && temp->right != node) {
                    temp = temp->right;
                }

                // make link from temp -> node.
                if(temp->right == nullptr) {
                    temp->right = node;
                    node = node -> left;
                }

                // clear the link and jump to the previous root.
                else {
                    temp->right = nullptr;
                    ans.push_back(node->val);
                    node = node -> right;
                }
            }
        }

        return ans;

    }
};