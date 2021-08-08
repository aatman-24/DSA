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

Question : 226. Invert Binary Tree
Topic :BT
Problems : https://leetcode.com/problems/invert-binary-tree/
==============================> Explanation <=============================================

- idea is that,

for every node, swap it left child and right child.

*/


/*
==============================> Edge Case <=============================================



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
    
    // O(N) + O(N)[Auxiliary Space] Recursive.
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == nullptr)
            return nullptr;

        TreeNode* rightChild = root -> right;
        root -> right = root -> left;
        root -> left = rightChild;

        invertTree(root -> left);
        invertTree(root -> right);

        return root;        
    }

    // O(N) + O(N) DFS Stack 
    TreeNode* invertTree(TreeNode* root) {

        if(root == nullptr)
            return nullptr;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {

            TreeNode* node = st.top(); st.pop();

            TreeNode* rightChild = node -> right;
            node -> right = node -> left;
            node -> left = rightChild;

            if(node -> left)
                st.push(node->left);

            if(node -> right)
                st.push(node->right);
        }

        return root;
    }


    // O(N) + O(N) BFS level order traversal.
    TreeNode* invertTree(TreeNode* root) {

        if(root == nullptr)
            return nullptr;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            TreeNode* node = q.front(); st.pop();

            TreeNode* rightChild = node -> right;
            node -> right = node -> left;
            node -> left = rightChild;

            if(node -> left)
                q.push(node->left);

            if(node -> right)
                q.push(node->right);
        }

        return root;
    }
};