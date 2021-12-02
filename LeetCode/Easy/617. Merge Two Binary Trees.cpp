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

Question: 617. Merge Two Binary Trees
Topic : Tree
Problems : https://leetcode.com/problems/merge-two-binary-trees/
==============================> Explanation <=============================================

Traverse the tree and make the new node of both node value sum. Either one of the is null return second one.

==============================> Apporach and Time Complexity <=============================================

1) Tree Traversal, Recursion
Time: O(N)
Space: O(1) 

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        // If root1 is null return root2 or viceversa.
        if(root1 == nullptr || root2 == nullptr) {
            if(root1)
                return root1;
            return root2;
        }


        // Create root node with sum value.
        TreeNode* root = new TreeNode(root1->val + root2 -> val);
        root -> left = mergeTrees(root1->left, root2->left);
        root -> right = mergeTrees(root1->right, root2->right);

        return root;
    }
};