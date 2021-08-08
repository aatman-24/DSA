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

Question : 236. Lowest Common Ancestor of a Binary Tree
Topic :BT
Problems : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

==============================> Explanation <=============================================
1) First time (left & right) or (left && current) or (right && current) is true means we
found our LCA. Just make the left and right call.

Question given that, p and q are in BST that's why second solution work.



2) Concept is same. 
But here we return the node like (if we found on left side and right side is null) return left side node.
(if we found on right side and left side is empty) return right side node.
(if both are not empty) that time return current node.


When q is child of p that time LCA is p. So it return itself in every recursive call. Q is not found. 
Because we never expand the p children. Because if q is p children the LCA is p itself so we return
it directly.

If p and q is separate then it return both itself that time both are not null. That time we return
current node when first time this situation occurs.


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
    bool findLCA(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &LCA) {

        if(root == nullptr)
            return false;

        if(LCA == nullptr) {

            bool left = findLCA(root->left, p, q, LCA);
            bool right = findLCA(root -> right, p, q, LCA);
            bool givenRootIsOneOfNode = (root == p || root == q);

            if((left && right) || (left && givenRootIsOneOfNode) || (right && givenRootIsOneOfNode))
                LCA = root;

            return (left || right || givenRootIsOneOfNode);
        }
        
        return false;
    }



    // O(N).
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        TreeNode* LCA = nullptr;
        bool res = findLCA(root,  p,  q, LCA);
        return LCA;
    }




    // O(N)
    // In the algorithm it is clear that, either we found the p or q in one side or (one in left and 
    // one on right). So that's why its work.
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // base condition.
        if(root == nullptr || root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);

        // right side is not found so we return left side.
        if(right == nullptr)
            return left;            // It can be null or p or q.

        // if left side is not found we return right side.
        else if(left == nullptr)
            return right;           // It can be null or p or q.

        // left and right not null. (means on left tree and right tree have p and q separtely).
        return root;
    }


    // when the one of the p or q is LCA then it return itself in every call. Because other q node
    // is not found in tree elsewhere that's why. And that time q must be child of p. So no need to
    // check for that.


};