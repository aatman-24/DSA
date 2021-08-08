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

Question : 113. Path Sum II
Topic :BT
Problems :https://leetcode.com/problems/path-sum-ii/

==============================> Explanation <=============================================

Valid path -> If any node which is not null and both its child is null. Means Ending of path. 
This is valid path all others are not valid.

Follow-up = 112. Path Sum.


We need all the possible path so we don't stop if we found then also.
Same 112 but here we store all the path into the vector. 


Keep track of element. Using Backtracking.


It can be solved many ways:

1) Recursion (here)
2) DFS + Queue
3) BFS + Stack

*/


/*
==============================> Edge Case <=============================================
(root == NULL)

1) Either we come from the parent node which have one child node. Which is not valid path.

2) Given root is null. Which is also not valid path.

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
    vector<vector<int>> ans;

    void helper(TreeNode* root, int curSum, int targetSum, vector<int> &temp) {

        if(root == NULL)
            return;

        temp.push_back(root -> val);

        if(root -> left == NULL && root -> right == NULL) {
            if(root->val + curSum == targetSum) {
                ans.push_back(temp);
            }
        }

        
        helper(root->left, curSum + root->val, targetSum, temp);
        helper(root->right, curSum + root->val, targetSum, temp);

        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        helper(root, 0, targetSum, temp); 
        return ans;   
    }
};

