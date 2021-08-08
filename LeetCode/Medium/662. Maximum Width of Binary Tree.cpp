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

Question : 662. Maximum Width of Binary Tree
Topic :BT
Problems : https://leetcode.com/problems/maximum-width-of-binary-tree/

==============================> Explanation <=============================================
Level Order Travesal + Node position.


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

#define ll long long

class Solution {
public:

        // BFS Solution
        // Level Order Traversal and for the width keep track of node location.
        // If current node is i then its left child at(2i+1) and right child at(2i+2).
        int widthOfBinaryTree(TreeNode* root) {

        if(root == nullptr)
            return 0;

        // Keep track of current node and its position.
        queue<pair<TreeNode*,unsigned long long>> q;

        // Ans is with for the root node.
        int ans = 1;
        unsigned long long left, right;

        q.push({root,0});

        while(!q.empty()) {

            unsigned long long size = q.size();

            // Mark left and right as zero.
            left=0; right=0;

            for(unsigned long long i = 0; i < size; i++) {

                TreeNode* node = q.front().first;
                unsigned long long parent_index = q.front().second;
                q.pop(); 

                // Keep track of leftmost and rightmost node into the current level.
                if(left == 0) left = parent_index;
                else right = parent_index;

                if(node->left) {
                    // left child index.
                    unsigned long long index = 2 * parent_index + 1;
                    q.push({node->left, index});
                }

                if(node->right) {
                    // right child index.
                    unsigned long long index = 2 * parent_index + 2; 
                    q.push({node->right, index});
                }

                // If current level is covered by left and also right node then and only we update
                // the width.
                if(left != 0 && right != 0)
                    ans = max(ans, int(right-left+1));
            }
        }

        return (int)ans;
    }



    // DFS Solution = O(N) + O(N)
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;

        // Index i represent vec[i] = {left_most_location, right_most_location} into ith level.  
        vector<pair<unsigned long long , unsigned long long >> vec;       


        return dfs(root, 0, 1, vec);
    }
    
    int dfs(TreeNode* root, int level, unsigned long long  order, vector<pair<unsigned long long , unsigned long long >>& vec){
        
        if(root == NULL)return 0;
        
        // When New level find put the {left,right} = {location, location};
        if(vec.size() == level)vec.push_back({order, order});
        // Otherwise just update the {right} location.
        else vec[level].second = order;
        
        // return can be current level (right-left) or from the children level.
        return max({int(vec[level].second - vec[level].first + 1), dfs(root->left, level + 1, 2*order, vec), dfs(root->right, level + 1, 2*order + 1, vec)});
    }



};