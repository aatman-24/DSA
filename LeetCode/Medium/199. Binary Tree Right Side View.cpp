#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

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

Question : 199. Binary Tree Right Side View
Topic : Queue, Tree
Problems : https://leetcode.com/problems/binary-tree-right-side-view/


/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================

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


    // O(N) - O(1)
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int n = q.size();
            int i = 0;
            while(i < n) {
                TreeNode *node = q.front(); q.pop();

                if(i == n - 1) {
                    ans.push_back(node->val);
                }

                if(node -> left)
                    q.push(node->left);

                if(node -> right)
                    q.push(node->right);

                i++; 
            }
        }

        return ans;

    }


    void recursion(TreeNode *root, int level, vector<int> &res) {
        if(root==NULL) return ;
        if(res.size()<level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }
    
    // O(N) - O(1)
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 1, res);
        return res;
    }
};