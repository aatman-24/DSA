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

Question : 515. Find Largest Value in Each Tree Row
Topic :BT
Problems : https://leetcode.com/problems/find-largest-value-in-each-tree-row/

==============================> Explanation <=============================================
- Level order travesal.

- Here i performed using DFS.
- We can use bfs also. and each order keep track of maximum value and push back into ans vector.

BFS = O(N) + O(N) Space = Queue

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

    void dfs(TreeNode* root, int currentLevel, vector<int> &ans) {

        if(root == nullptr) {
            return;
        }

        if(ans.size() == currentLevel) {
            ans.push_back(root->val);
        }
        else {
            ans[currentLevel] = max(ans[currentLevel], root -> val);
        }

        dfs(root -> left, currentLevel + 1,  ans);
        dfs(root -> right, currentLevel + 1, ans);
    }



    vector<int> largestValues(TreeNode* root) {

        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
};