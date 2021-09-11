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

Question : 110. Balanced Binary Tree
Topic : BT
Problems : https://leetcode.com/problems/balanced-binary-tree/

==============================> Explanation <=============================================

1) Brute Force = O(N^2)
2) & 3) Optimized = O(N)

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class solution {
public:


    // Brute Force = O(N^2)
    // From every node find its left and right depth. And again go the left and right child and perform
    // the same step. So it will take O(N^2).
    int depth (TreeNode *root) {
        if (root == NULL) return 0;
        return max (depth(root -> left), depth (root -> right)) + 1;
    }

    bool isBalanced (TreeNode *root) {
        if (root == NULL) return true;
        
        int left=depth(root->left);
        int right=depth(root->right);
        
        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }


    // Rathar than in One pass we can do it. Used Height which is pass by referernce so we change it
    // for every node.



    // O(N) - O(1).
    bool isBalanced(TreeNode* root, int &height) {

        if(root == nullptr) {
            return true;
        }

        int leftHeight = 0, rightHeight = 0;

        bool left = isBalanced(root -> left, leftHeight);
        bool right = isBalanced(root -> right, rightHeight);

        // height is updated here for the current node.
        height = max(leftHeight, rightHeight) + 1;

        // if left and right both are balanced then and only need to check otherwise return false.
        if(left && right) {

            if(abs(leftHeight - rightHeight) <= 1)
                return true;
            else 
                return false;
        }

       return false;

    }
        
    
    bool isBalanced(TreeNode* root) {
       int height = 0;
       return isBalanced(root, height);
    }


    // O(N) - O(1)
    int dfsHeight (TreeNode *root) {
        if (root == NULL) return 0;
        
        int leftHeight = dfsHeight (root -> left);
        if (leftHeight == -1) 
            return -1;

        int rightHeight = dfsHeight (root -> right);
        if (rightHeight == -1) 
            return -1;
        
        if (abs(leftHeight - rightHeight) > 1)  
            return -1;

        return max (leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode *root) {
        return dfsHeight (root) != -1;
    }
};