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

Question : 222. Count Complete Tree Nodes
Topic :BT
Problems : https://leetcode.com/problems/count-complete-tree-nodes/

==============================> Explanation <=============================================
- Complete Binary tree is tree in which last level can be incomplete except the last level all level is full filled.
      
Commplete Binary Tree:

        1
       / \
      2   3
     / \ 
    4  5 




- Full Binary Tree is tree in which all level are fully filled. Just like below once,
      
Full Binary Tree:

        1
       / \
      2   3
     / \ / \
    4  5 6  7

- If the Full binary tree height is h, then there is 2^h - 1 elements there. 
Here tree height is 3. 2^3 - 1 = 7 (nodes) are there.


So we used this concept to find the total node in Complete BT.

- we find the leftHeight and rightHeight of root->left and root->right node. If both are same then
tree is Full Binary Tree so direct use the equation. (leftHeight determine by only going left and
rightHeight is determine by only going to right).
- else 1(root) + countNode(root->left) + countNode(root->right).


Conclusion: In complete tree we find the full Binary tree and return the 2^h-1 element for that. If our
current node not make the full binary tree means we recursively find in the left and right child.

Time = O(logN*logN)

Why ? -> First for we traverse the height of tree so it is O(logN). 

Recursive Call -> 1 + countNode(root->left) + countNode(root->right)

- So One of the left or right tree must be Full binary Tree so this part is eliminated into the second
call because we using full binary tree concept(direct reutrn node) that's why. 
- Every time it half of the nodes remain to traverse 

logN + logN/2 + logN/4 + logN/6 -> O(logN).  (logN because we travese the only left height and right height of tree not all
elements).

So overall time is = O((logN)^2).


Algorithm 2:

Same Concept is used but in differnt manner. Here we count the height of tree by only considering
the left child of tree.


Logic is that,

    find leftHeight, rightHeight.
    (if both are same means leftSubtree is full BST. and rightSubtree have the last level node).
        return 1(root) + (pow(2,leftHeight)-1)(full left BT nodes) + countNodes(root->right);
    
    if both are not same leftHeigh = rightHeight + 1. 
    That time rightSubtree is full BST with height = leftHeight-1.
        
        return 1(root) + countNodes(root->left) + (pow(2,rightHeight)-1)(rightSubtree full BT);



Time = O((logN)^2)

- Every time half of the tree is eliminated either left or right. And finding the height of left and
right subtree take O(logN).

So overall time = O(logN)(height of tree) * O(logN)(maximum recursive call) = O((logN)^2).



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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int leftHeight(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return leftHeight(root->left) + 1;
    }

    int rightHeight(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return rightHeight(root->right) + 1;
    }


    int countNodes(TreeNode* root) {

        if(root == nullptr)
            return 0;

        int lh = leftHeight(root->left);
        int rh = rightHeight(root -> right);

        if(lh == rh) {
            return pow(2, lh+1) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root -> right);

    }

// Solution 2:




    // Height is decided by only the left child of tree.
    int height(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return height(root->left) + 1;
    }


    int countNodes(TreeNode* root) {
        
        if(root == nullptr)
            return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Last level Last node is reside on the rightSubtree. 
        // leftSubtree is full Binary Tree.
        if(leftHeight == rightHeight) {
            return 1 + (pow(2,leftHeight)-1) + countNodes(root->right);
        }   


        // Last level last node is on the leftSubtree. rightSubtree is full BT.
        // but remember rightSubtree height is = (leftSubtreeHeight - 1) Now. 
        return 1 + countNodes(root->left) + (pow(2,rightHeight)-1);
    }


    // This solution just think this two condition,


  //   (leftHeight == rightHeight)         
  //       1                                   
  //      / \
  //     2   3
  //    / \ / 
  //   4  5 6  


  //   (leftHeight == rightHeight + 1)

  //       1                                   
  //      / \
  //     2   3
  //    / \ / \ 
  //   4  5 6  7
  //  / \
  // 8   9



};