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

Question : 129. Sum Root to Leaf Numbers
Topic :BT
Problems : https://leetcode.com/problems/sum-root-to-leaf-numbers/

==============================> Explanation <=============================================

Follow-up - 

1) 112. Path Sum
2) 113. Path Sum II


Just How to Form the number is change otherwise same problem (Variant of Path Sum).

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

    void helper(TreeNode* root, int &curNumber, int &total) {

        if(root == NULL)
            return;

        // update the curNumber. Add the root->val digit at last.
        curNumber = curNumber * 10 + root -> val;

        if(root -> left == NULL && root -> right == NULL)
            total += curSum;

        helper(root -> left, curNumber, total);
        helper(root -> right, curNumber, total);

        // Backtracking.
        curNumber /= 10;
    }



    int sumNumbers(TreeNode* root) {
        int total = 0;
        int curNumber = 0;
        helper(root, curNumber, total);
        return total;
    }
    
};