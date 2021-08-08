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

Question : 958. Check Completeness of a Binary Tree
Topic :BT
Problems : https://leetcode.com/problems/check-completeness-of-a-binary-tree/

==============================> Explanation <=============================================

1) BFS - Using Level Order Traversal. Once we found the null then there should not be any other node
in that level.


2) DFS - Amazing.

- count the total number of nodes. Using DFS. all nodes is complete binary tree then it is
on the right position.

- After one more pass on dfs. 

- If there is any position which should be filled up by the nodes in that
level which is not visited yet and current position is null then 
when we visit this not visited that time indexOfNode > totalNode.

- Conclusion:

- If we count the total number nodes using dfs. 

- In second pass, nodeIndex <= totalNode must be hold. If it is not then, the some node left nullptr
on left side in level which is wrong.

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


    // BFS O(N) + O(N)
    bool isCompleteTree(TreeNode* root) {
        if(root == nullptr)
            return true;

        queue<TreeNode*> q;
        q.push(root);

        bool end = false;

        while(!q.empty()) {

                TreeNode* node = q.front(); q.pop();

                if(node != nullptr) {
                    if(end) return false;
                    q.push(node->left);
                    q.push(node->right);
                }
                else {
                    end = true;
                }
        }

        return true;
    }






    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }


    bool dfs(TreeNode* root, int total, int idx) {

        if(root == nullptr)
            return true;

        if(idx > total)
            return false;

        return dfs(root->left, total, idx*2) && dfs(root->right, total, idx*2+1);
    }

    // DFS O(N) + O(1).
    bool isCompleteTree(TreeNode* root) {

        int total = countNodes(root);
        return dfs(root, total, 1);
    }
};



