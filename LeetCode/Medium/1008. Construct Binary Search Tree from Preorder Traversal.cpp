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

Question : 1008. Construct Binary Search Tree from Preorder Traversal
Topic :BT
Problems : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

==============================> Explanation <=============================================
- Given That Preorder traversal is valid and tree must be constructed that's why direct we can
use preorder traversal and keep track of min and max value and build the tree.


Time -> O(N)
Auxiliary Space -> O(H)

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

    TreeNode* bstFromPreorder(vector<int>& preorder, int min_value, int max_value, int &index) {

        if(index == preorder.size()-1)
            return nullptr;
        
        if(min_value < preorder[index+1] && preorder[index+1] < max_value) {
            
            TreeNode* node = new TreeNode(preorder[++index]);
            node -> left = bstFromPreorder(preorder, min_value, node->val, index);
            node -> right = bstFromPreorder(preorder, node->val, max_value, index);
            return node;
            
        }
        
        return nullptr;
        
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = -1;
        return bstFromPreorder(preorder, INT_MIN, INT_MAX, index);
    }
};