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


/*
==============================> Description <=============================================

Question: 1448. Count Good Nodes in Binary Tree
Topic : DFS, BFS
Problems : https://leetcode.com/problems/count-good-nodes-in-binary-tree/
==============================> Explanation <=============================================
- Keep track of Maximum Value from root -> currentNode.

==============================> Apporach and Time Complexity <=============================================

1) DFS:
Time: O(N)
Space: O(N)(Aux)

2) BFS:
Time: O(N)
Space: O(N)(Queue)

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
    void dfs(TreeNode* root, int max_value, int &count) {
        if(root == nullptr)
            return;

        if(root -> val >= max_value)
            count++;

        max_value = max(max_value, root->val);

        dfs(root -> left, max_value, count);
        dfs(root -> right, max_value, count);
    }

    int goodNodes(TreeNode* root) {
        int count = 0, max_value = INT_MIN;
        dfs(root, max_value, count);
        return count;
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
    int goodNodes(TreeNode* root) {

        queue<pair<TreeNode*,int>> q;
        q.push({root, INT_MIN});

        int count = 0;

        while(!q.empty()) {
            
            int size = q.size();
            
            for(int j = 0; j < size; j++) {
            
                auto [node, parentValue] = q.front(); q.pop();

                if(node -> val >= parentValue)
                    count++;

                if(node -> left) 
                    q.push({node->left, max(node->val, parentValue)});
                
                if(node -> right) 
                    q.push({node->right, max(node->val, parentValue)});
            }
        }

        return count;
    }
};