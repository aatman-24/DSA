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

Question: 111. Minimum Depth of Binary Tree
Topic : Binary Tree
Problems : https://leetcode.com/problems/minimum-depth-of-binary-tree/

==============================> Explanation <=============================================

- Find the height of both child and return minimum among them.
- Handle the base case when root is nullptr return 0.
- If any time except the root node, curr node is nullptr return some big value.

==============================> Apporach and Time Complexity <=============================================

1) Binary Tree
Time: O(N)
Space: O(H)(Aux Space)

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

    int minDepthSupport(TreeNode* root) {
            
        if(root == nullptr)
            return 10000;

        if(root->left == nullptr && root -> right == nullptr)
            return 1;

        return  min(minDepthSupport(root->left), minDepthSupport(root->right)) + 1;
    }


    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return minDepthSupport(root);
    }
};