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

Question : 897. Increasing Order Search Tree
Topic :BT
Problems : https://leetcode.com/problems/increasing-order-search-tree/

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

    TreeNode* previous = nullptr; 
    TreeNode* new_root =  nullptr;
    

    // Keep track of previous node in inorder traversal.

    void inorder(TreeNode* root) {

        if(root == nullptr)
            return;

        inorder(root -> left);

        if(new_root == nullptr)
            new_root = root;

        if(previous != nullptr) {
            root->left = nullptr;   // root -> left is previous.
            previous->right = root;
        }

        previous = root;
        
        inorder(root -> right); 
    }

    // O(N) + O(H) 
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return new_root;  
    }
};