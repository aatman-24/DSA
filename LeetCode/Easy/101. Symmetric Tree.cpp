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

Question : 101. Symmetric Tree
Topic :BT
Problems : https://leetcode.com/problems/symmetric-tree/
==============================> Explanation <=============================================

- idea is that,
Symmetry Checking with mirror line, Check the node on both side or mirror line. 

lftSide and rightSide is current node on both side.

when we check mirror left side, [left side]  lftSide -> left == rightSide -> right
                                             lftSide -> right== rightSide -> left

Check above one recursively. (if either lftSide or rightSide is null then second one also must be null.)
otherwise check leftSide and rightSide current node value.

- Second Solution Iterative is just copy of above,

replacement of recursion with stack.

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
    

    bool isSymmetric(TreeNode* leftChild, TreeNode* rightChild) {

        if(leftChild == nullptr) {
            return rightChild == nullptr;
        }

        if(leftChild -> val == rightChild -> val) {
            return isSymmetric(leftChild -> left, rightChild -> right) && isSymmetric(leftChild -> right, rightChild -> left);
        }

        return false;
    }

    // Recursive O(N) + O(N) [Aux]
    bool isSymmetric(TreeNode* root) {

        if(root == nullptr)
            return true;

        return isSymmetric(root -> left, root -> right);
    }


    // Iterative. Using Stack O(N) + O(N)
    bool isSymmetric(TreeNode* root) {

        if(root == nullptr)
            return true;

        stack<TreeNode*> leftChild, rightChild;

        leftChild.push(root -> left);
        rightChild.push(root -> right);

        while(!leftChild.empty() && !rightChild.empty()) {

            TreeNode* lftNode = leftChild.top(); leftChild.pop();
            TreeNode* rhtNode = rightChild.top(); rightChild.pop();

            if(lftNode && rhtNode)
                if(lftNode -> val != rhtNode -> val) return false;

            if((!lftNode && rhtNode) || (lftNode && !rhtNode)) return false;

            if(lftNode) {
               leftChild.push(lftNode->left);
               leftChild.push(lftNode->right); 
            }
            
            if(rhtNode) {
                rightChild.push(rhtNode->right);
                rightChild.push(rhtNode->left);
            }
        }


        return true;
    }
};