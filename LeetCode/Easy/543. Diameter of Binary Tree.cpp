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

Question : 543. Diameter of Binary Tree
Topic :BT
Problems : https://leetcode.com/problems/diameter-of-binary-tree/
==============================> Explanation <=============================================
- Diameter of Binary Tree is longest path between any two nodes.

So it can be defined with any node,

= max(leftDiameter, rightDiamter, {leftHeight + rightHeight + 1(current node)})

- So max-Diameter can be pass through the current node or not. When the max-diameter not pass through
the current node that time it pass throught its child. So we take maximum of it.

- And if pass through the current node then it is leftHeight + rightHeight + current node.

Here I merge leftDiameter, rightDiamter this to single one. Whenever we found the max-diameter we store
into the result. And recursively check wheather current node is part of diameter or not. 

If leftHeight + rightHeight + 1(current node) > maxDiameter means current node is part of it.



Time = O(N)
Space = O(H) (Height of Tree.)

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
    
    // O(N) + O(Height)
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        int val = diameterOfBinaryTree(root, diameter);
        return diameter-1;
    }


    int diameterOfBinaryTree(TreeNode* root, int &maxDiameter) {

       if(root == nullptr)
          return 0;

        int leftHeight = diameterOfBinaryTree(root->left, maxDiameter);
        int rightHeight = diameterOfBinaryTree(root->right, maxDiameter);

        maxDiameter = max(maxDiameter, leftHeight+rightHeight+1);

        return max(leftHeight, rightHeight) + 1;
    }
};