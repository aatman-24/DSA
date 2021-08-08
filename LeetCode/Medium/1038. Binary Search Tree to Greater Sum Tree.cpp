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

Question :  1038. Binary Search Tree to Greater Sum Tree
Topic : Tree
Problems : https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

==============================> Explanation <=============================================
Idea, right -> root -> left.
- perform cummulative sum from right to upward side. For left side node value is added directly with
currently cummlative sum. And we pass only the right side sum not left side sum for any root.


*/


/*
==============================> Edge Case <=============================================

*/

class Solution {

public:
    
    int reversedPreOrder(TreeNode* root, int &curSum) {

        if(root == NULL) {
            return curSum;
        }

        // Go to Right.
        int rightSum = reversedPreOrder(root->right, curSum);

        // Update the current root.
        curSum = root -> val = root -> val + curSum;

        // Go to left with updated curSum.
        int lefSum = reversedPreOrder(root->left, curSum);

        // Return only curSum.
        return curSum;
    }

    // reversed preorder trversal O(N) - O(height). [into recursive stack into memory.]
    TreeNode* bstToGst(TreeNode* root) {
        int curSum = 0;
        curSum = reversedPreOrder(root, curSum);
        return root;
    }


    // reversed preorder trversal O(N) - O(height). [into recursive stack into memory.] (same)
    int pre = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if (root->right) bstToGst(root->right);
        pre = root->val = pre + root->val;
        if (root->left) bstToGst(root->left);
        return root;
    }

};