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

Question : 103. Binary Tree Zigzag Level Order Traversal
Topic : Stack, Queue, Tree
Problems : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/


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

    // O(N) + O(N) [Using Two stack]
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> result;
        if(root == NULL) return result;
        
        stack<TreeNode*> main;
        vector<int> level;

        main.push(root);
        bool leftToRight = false;

        while(!main.empty()) {

            stack<TreeNode*> tmp;
            
            while(!main.empty()) {

                TreeNode* node = main.top(); main.pop();
                level.push_back(node->val);

                if(leftToRight) {

                    if(node -> right) {
                        tmp.push(node->right);
                    }

                    if(node -> left) {
                        tmp.push(node->left);
                    }

                }
                else {

                    if(node -> left) {
                        tmp.push(node->left);
                    }

                    if(node -> right) {
                        tmp.push(node->right);
                    }
                }
            }

            main = tmp;
            leftToRight = !leftToRight;
            
            result.push_back(level);
            level.clear();
        }

        return result;
    }

    // O(N) + O(N) [Using single queue]
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> result;
        if(root == NULL) return result;
        
        queue<TreeNode*> q;
        vector<int> level;

        q.push(root);
        bool leftToRight = true;

        while(!q.empty()) {

            int n = q.size();

            int inc = (leftToRight) ? 1 : -1;
            int start = (leftToRight) ? 0 : n - 1;

            level.assign(n,0);
            
            while(n--) {
                
                TreeNode* node = q.front(); q.pop();
                level[start] = (node->val);
                start += inc;

                if(node -> left) {
                    q.push(node->left);
                }

                if(node -> right) {
                    q.push(node->right);
                }

            }
            leftToRight = !leftToRight;
            result.push_back(level);
        }

        return result;
    }


};