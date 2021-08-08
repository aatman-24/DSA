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

Question : 998. Maximum Binary Tree II
Topic :BT
Problems : https://leetcode.com/problems/maximum-binary-tree-ii/

==============================> Explanation <=============================================
https://leetcode.com/problems/maximum-binary-tree/

- This question some needs understand well. Given root is already the maximum binary tree. But question
is that the tree which is created that time whatever array is given in that array you should add
the given value at the end of that array again create a maximum binary tree and return that.

- Here we did not given the array but tree root node is given.

Brute Force: -> Tree -> get Array -> Append value at the back -> Reconstruct the array.   
                O(N)(DFS on TREE) + O(N) [space for array]

Optimize -> Already we know that, whatever value is append is at the end of array so we can traverse only
            the right side of tree.

            and check root.val > val if yes, then we return root.
            if it is not means that, there is some other value is left in tree, 
            so we create a new node with given value and append the remaining tree on the left side of
            current node and return it.


        Why we add left Side remaining tree ?


            - For the current state if we choose the ith as maximum value node.

                A[...i-1] < A[i] < A[i+1...]

            So when [4(visited), 1, 3(newly added)] so from [1,3] we choose the 3 as max node.
            that's why remaining tree [1] is left on the new node. Because of above rules.
    
            Current Tree.

            4
             \
              1

           Updated Tree.

           4 
            \ 
             3
            /
           1

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

    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root == nullptr) {
            return new TreeNode(val);
        }

        if(root -> val > val) {
            root -> right = insertIntoMaxTree(root -> right, val);
            return root;
        }
        else {
            TreeNode* node = new TreeNode(val);
            node -> left = root;
             return node; 
        }
    }
};