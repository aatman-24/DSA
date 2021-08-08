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

Question : 513. Find Bottom Left Tree Value
Topic :BT
Problems : https://leetcode.com/problems/find-bottom-left-tree-value/

==============================> Explanation <=============================================
- Level order travesal.

- Here i performed using DFS.
- We can use bfs also. (and go right to left) so no need to keep track of first value.

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

    void dfs(TreeNode* root, int currentLevel,  int &maximumLevel, int &ans) {

        if(root == nullptr) {
            return;
        }

        if(currentLevel > maximumLevel) {
            maximumLevel = currentLevel;
            ans = root -> val;
        }

        dfs(root -> left, currentLevel + 1, maximumLevel, ans);
        dfs(root -> right, currentLevel + 1, maximumLevel, ans);
    }

    // O(N) - O(logN).
    int findBottomLeftValue(TreeNode* root) {
        int ans, currentLevel = 0, maximumLevel = -1;
        dfs(root, currentLevel, maximumLevel, ans);
        return ans;
    }
};
    