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

Question :  1315. Sum of Nodes with Even-Valued Grandparent
Topic : Tree
Problems : https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

==============================> Explanation <=============================================
Keep track of parent and grandparent value. So children can knew his grandparent value.

-DFS

Time = O(N) + O(1)
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


    void helper(TreeNode* root, int grandParent, int Parent, int &curSum) {

        if(root == NULL)
            return;

        if(grandParent % 2 == 0)
            curSum += root -> val;

        // Make grandparent <- parent
        // and Parent <- currentNode.val
        if(root -> left)
            helper(root->left, Parent, root->val, curSum);

        if(root -> right)
            helper(root -> right, Parent, root->val, curSum);
    }


    // DFS = O(N) + O(1)
    int sumEvenGrandparent(TreeNode* root) {

        int sum = 0;
        helper(root, -1, -1, sum);

        return sum;

    }
};