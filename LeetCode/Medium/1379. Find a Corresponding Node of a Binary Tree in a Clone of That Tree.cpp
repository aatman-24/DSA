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

Question :  1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
Topic : Tree
Problems : https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

==============================> Explanation <=============================================


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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    // Simple DFS ONE PASS.
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

        if(original == target) {
            return cloned;
        }

        if(original == nullptr) {
            return nullptr;
        }

        TreeNode* left = getTargetCopy(original -> left, cloned -> left, target);
        if(left != NULL) 
            return left;

        TreeNode* right = getTargetCopy(original -> right, cloned -> right, target);
        return right;
    }
};