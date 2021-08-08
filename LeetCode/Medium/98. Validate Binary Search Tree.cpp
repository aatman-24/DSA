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

Question :  98. Validate Binary Search Tree
Topic : Tree
Problems : https://leetcode.com/problems/validate-binary-search-tree/

==============================> Explanation <=============================================

Time = O(N) + O(1)
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


    bool helper(TreeNode* root, int min_value, int max_value) {

        if(root == NULL)
            return true;

        if(min_value < root->val && root->val < max_value) {

            bool left = helper(root->left, min_value, min(max_value, root->val));

            if(left) {
                bool right = helper(root -> right, max(min_value, root->val), max_value);
                if(left && right)
                    return true;

            }
        }

        return false;
    }

    // INT_MIN AND INT_MAX IS NOT WORK WHILE NODE CONTAIN THE VALUE [INT_MIN,INT_MAX].
    // both are included. If you used LONG_MIN, LONG_MAX then it is okay that time
    // but not looks good.
    bool isValidBST(TreeNode* root) {

        return helper(root, INT_MIN, INT_MAX);

    }




    // STANDARD METHOD: INORDER MUST BE SORTED.
    // Use node rathar than the value.
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max) {

        if(root == NULL)
            return true;

        if(min && min -> val >= root -> val || (max && root -> val >= max->val))
            return false;

        return helper(root->left,min,root) && helper(root->right,root,max);
    }


    bool isValidBST(TreeNode* root) {

        return helper(root, nullptr, nullptr);

    }

};