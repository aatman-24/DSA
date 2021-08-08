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

Question : 938. Range Sum of BST
Topic :BT
Problems : https://leetcode.com/problems/range-sum-of-bst/
==============================> Explanation <=============================================
- can be solve using stack. (Iterative)
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


    // O(N) Worst Case. Otherwise Early Stop.
    int rangeSumBST(TreeNode* root, int L, int R) {

        if(root == nullptr)
            return 0;

        if (root->val < L) return rangeSumBST(root->right, L, R); // left branch excluded.
        if (root->val > R) return rangeSumBST(root->left, L, R);  // right branch excluded.
        
        return root -> val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
        
    }
    
};