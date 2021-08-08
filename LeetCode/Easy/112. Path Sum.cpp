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

Question :  112. Path Sum
Topic :BT
Problems : https://leetcode.com/problems/path-sum/e/

==============================> Explanation <=============================================

Valid path -> If any node which is not null and both its child is null. Means Ending of path. 
This is valid path all others are not valid.
*/


/*
==============================> Edge Case <=============================================
(root == NULL)

1) Either we come from the parent node which have one child node. Which is not valid path.

2) Given root is null. Which is also not valid path.

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

    bool helper(TreeNode* root, int curSum, int targetSum) {

        // root is null means we land on the node from the one child parent node.
        // Or Base condition.
        if(root == NULL)
            return false;

        // Leaf node is node which does not have any child. Here we check the
        // Equality condition.

        // NOITCE: If root -> left  or root -> right is not null any of them is landed on
        // aboce condition so we return false.
        // In this Quesiton we Check for only Valid Path. When the Node both child is null
        // only that time we can say we reach to the end of path.
        if(root -> left == NULL && root -> right == NULL)
            return root->val + curSum == targetSum;

        if(helper(root->left, curSum + root->val, targetSum))
            return true;

        return helper(root->right, curSum + root->val, targetSum); 
    }

    // O(N) + O(height) -> Recusrion Stack Memory Otherwise O(1).
    bool hasPathSum(TreeNode* root, int targetSum) {
       return helper(root, 0, targetSum);
    }
};
