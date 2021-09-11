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

Question: 623. Add One Row to Tree
Topic : Tree, BFS, DFS
Problems : https://leetcode.com/problems/add-one-row-to-tree/  
==============================> Explanation <=============================================
- We Traverse only upto d-1 depth. So maximum we can visit the node is 2^(d-1) if it cmplt
binary tree. So time and space can be related.

2) Can be solved using DFS but a little bit complex not too much. but Solve the problem of
level order traversal with DFS is not good idea in interview. And it time and space complexity
is same with BFS.

==============================> Apporach and Time Complexity <=============================================

1) BFS Tree Level Order Traversal:
Time: O(2^(d-1)) < O(N)(Here)
Space: O(2^(d-1)) < O(N)(Here)

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

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        // Base Case.
        if(depth == 1) {
            TreeNode* nw_root = new TreeNode(val);
            nw_root -> left = root;
            return nw_root;
        }

        int cur_depth = 1;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int size = q.size();
            
            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front(); q.pop();
                
                // Do modification. After that Don't add node into the queue.
                if(cur_depth == depth - 1) {
                    TreeNode* lft = new TreeNode(val);
                    TreeNode* rht = new TreeNode(val);

                    lft -> left = node -> left;
                    rht -> right = node -> right;

                    node -> left = lft;
                    node -> right = rht;
                }
                else {

                    if(node -> left)
                        q.push(node -> left);

                    if(node -> right)
                        q.push(node -> right);
                }
            }

            // We break it after we visited depth-1 all nodes.
            cur_depth++;
            if(cur_depth >= depth)
                break;
        }


        return root;

    }
};