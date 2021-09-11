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

Question : 404. Sum of Left Leaves
Topic : BT
Problems : https://leetcode.com/problems/sum-of-left-leaves/

==============================> Explanation <=============================================

Recursive:
    Both are same. O(N) + O(1) + O(H) (Recursion Auxiliary Space)

Iterative:
    Using Stack the same thing can be performed. O(N) + O(N).



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

class solution {
public:


    int sumOfLeftLeaves(TreeNode* root, bool fromLeft=false) {

        if(root == nullptr)
            return 0;

        int sum = 0;

        if(root -> left == nullptr && root -> right == nullptr && fromLeft)
            return root -> val;

        sum += sumOfLeftLeaves(root->left, true);
        sum += sumOfLeftLeaves(root -> right, false);

        return sum;

    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(root == null) 
            return 0;
        
        int ans = 0;
        if(root->left != null) {
            if(root->left->left == null && root->left->right == null) 
                ans += root->left->val;
            else 
                ans += sumOfLeftLeaves(root->left);
        }

        ans += sumOfLeftLeaves(root->right);
        
        return ans;
    }
};