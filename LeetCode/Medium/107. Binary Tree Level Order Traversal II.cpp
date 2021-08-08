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

Question :  107. Binary Tree Level Order Traversal II
Topic : Tree
Problems : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

==============================> Explanation <=============================================
Same. Follow up - 102. Binary Tree Level Order Traversal.

Reverse the result.

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

     vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> ans;
        
        if(root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int size = q.size();
            vector<int> level(size);

            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                level[i] = curr->val;

                if(curr -> left)
                    q.push(curr->left);

                if(curr -> right)
                    q.push(curr->right);

                q.pop();
            }

            ans.push_back(level);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }




    vector<vector<int>> ret;

    void buildVector(TreeNode *root, int depth)
    {
        if(root == NULL) return;

        // When the new depth/level is found and the first vector<int> into the ret. So It can be used.
        if(ret.size() == depth)
            ret.push_back(vector<int>());
        
        ret[depth].push_back(root->val);
        

        // Using preorder the in level (left -> right) order is maintained.
        buildVector(root->left, depth + 1);
        buildVector(root->right, depth + 1);
    }

    // Using DFS. O(N) + O(1)
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        buildVector(root, 0);
        reverse(ret.begin(), ret.end());
        return ret;
    }

};
