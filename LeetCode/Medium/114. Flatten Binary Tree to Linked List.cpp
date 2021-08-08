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

Question : 114. Flatten Binary Tree to Linked List
Topic :BT
Problems :https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

==============================> Explanation <=============================================

Flatten the left part of node. After that Re-Link the left part on right side of parent while
copying the right node address. Go until the node->right != NULL. Joint the copied right
node there.

And call the flatten on that node again.


Conclusion:
- First flatten the left part.
- Relink on right side.
- Flattent the right part.


Check AC video.

*/


/*
==============================> Edge Case <=============================================


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
    void flatten(TreeNode* root) {
        
    if(root == NULL || (root -> left == NULL && root -> right == NULL)) 
        return;

    if(root -> left != NULL) {

        flatten(root -> left);

        TreeNode* temp = root -> right;
        root -> right = root -> left;

        // Make the left of root NULL after relink.
        root -> left = NULL;

        TreeNode* t = root -> right;
        while(t -> right != NULL) {
            t = t -> right;
        }

        // Join the right node after the left flatten list.
        t -> right = temp;
    }

    flatten(root -> right);
    }
};