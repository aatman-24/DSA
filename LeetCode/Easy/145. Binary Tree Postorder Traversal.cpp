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

Question : 145. Binary Tree Postorder Traversal
Topic :BT
Problems : https://leetcode.com/problems/binary-tree-postorder-traversal/

==============================> Explanation <=============================================



*/


/*
==============================> Edge Case <=============================================


*/


/*

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
    
   void postorder(TreeNode* root, vector<int> &ans) {
        if(root == nullptr)
            return;
        
         postorder(root->left, ans);
         postorder(root->right, ans);
        ans.push_back(root->val);
    }
    
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }

};