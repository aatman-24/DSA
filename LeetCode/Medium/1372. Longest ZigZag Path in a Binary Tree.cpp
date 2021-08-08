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

Question : 1372. Longest ZigZag Path in a Binary Tree
Topic :BT
Problems : https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

==============================> Explanation <=============================================
Both are same.


Just Expand either left or right. If we come from left then in child we expand right and vice versa.
And also keep track of longest intermidatory zigzag.

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

    // leftDirection mean that current node is left child of its parent.
    int helper(TreeNode* root, bool leftDirection, int &ans) {

        if(root == nullptr)
            return 0;

        int left = 0, right = 0;

        if(root -> left)
            left = helper(root->left, true, ans);

        if(root -> right)
            right = helper(root->right, false, ans);

        // So when it is left child of parent, then we add current into right child of currnet node.
        // and ans is maximize of {ans, right+1, left}.
        if(leftDirection == true) {
            ans = max(ans, max(right+1, left));
            return right+1;
        }
        
        // Otherwise vice versa.
        ans = max(ans, max(left+1, right));
        return left+1;
    }




    int longestZigZag(TreeNode* root) {

        int ans = 0;
        int left = helper(root->left, true, ans);
        int right = helper(root -> right, false, ans);

        return ans;
    }
};









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


    // Interview persepective.
    int helper(TreeNode* root, bool leftDirection, int &ans) {

        if(root == nullptr)
            return 0;

        int left = 0, right = 0;

        if(root -> left)
            left = helper(root->left, true, ans);

        if(root -> right)
            right = helper(root->right, false, ans);

        // When current node is left chlid of its parent ans = max(ans, left). Becuase we can not
        // expand the left child anymore because parent -> currnet is left. So we must go to right direction.
        // In case left direction contains more length zigzag then we store into the ans).
        if(leftDirection == true) {
            ans = max(ans, left);

            // So that's why we return (rightChild ZigZag + 1(current node)).
            return right+1;
        }
        
        // Reverse current node is right child we go to the left child and we don't expand right more.
        ans = max(ans, right);
        
        // So that's why we return (leftChild ZigZag + 1(current node)).
        return left+1;
    }




    int longestZigZag(TreeNode* root) {

        if(root == nullptr)
            return 0;

        int ans = 0;
        int left = helper(root->left, true, ans);
        int right = helper(root -> right, false, ans);

        // So here either root left Child containing zigzag is longest, or right child containing zigzag
        // is longest.
        // And it is also possible "some intermidate zigzag is longest in which left child and right
        // child is not part of that zigzag".
        return max({ans, left, right});

    }
};