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

Question : 572. Subtree of Another Tree
Topic :BT
Problems : https://leetcode.com/problems/subtree-of-another-tree/
==============================> Explanation <=============================================
- We check for every node whose value is same with the subtree root value. Is it both same or not.
- If yes we return it.
- Otherwise recursively check on left and right.

- idea comes from, path Sum problem.... 

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

    // This take O(M) subtree traversal.
    bool isSame(TreeNode* root, TreeNode* cur) {

        if(root == nullptr || cur == nullptr) {
            return cur == root;
        }

        return root -> val == cur -> val && isSame(root->left, cur->left) && isSame(root -> right, cur -> right);
    }


    // Time = O(N*M).
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(root == nullptr)
            return false;

        // If same call the isSame() to check subtree is same with current root node.
        if(root -> val == subRoot -> val)
            if(isSame(root, subRoot))
                return true;

        // We call on left after on right.
        if(isSubtree(root->left, subRoot))
            return true;

        retunr isSubtree(root -> right, subRoot);
    }
    
};