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

Question : 814. Binary Tree Pruning
Topic :BT
Problems : https://leetcode.com/problems/binary-tree-pruning/

==============================> Explanation <=============================================
- DFS on Tree.

- Check left child contain 1 or not. If not set it nullptr.
- Check right Child contain 1 or not. If not set in nullptr.

And recursively return the value for parent node,
    if left or right child or current node contain the 1 then return current node to the
    parent call.

Otherwise nullptr.

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

TreeNode* pruneTree(TreeNode* root) {

    if(root == nullptr)
        return root;

    root->left = pruneTree(root->left);

    root->right = pruneTree(root->right);

    if(root->left || root->right || root -> val == 1) 
        return root;

    return nullptr;
}
};