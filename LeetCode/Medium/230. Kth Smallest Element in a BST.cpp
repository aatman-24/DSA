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

Question : 230. Kth Smallest Element in a BST
Topic :BST
Problems : https://leetcode.com/problems/kth-smallest-element-in-a-bst/

==============================> Explanation <=============================================
- Ideas comes from,

Inorder travesal of BST return the sorted value. So we only need to make the recursive call until
we found the (k == count) after that don't need to again make the call.

*/


/*
==============================> Edge Case <=============================================


*/


/*

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

/*

Brute Force: 1) Use DFS to find out how many nodes are left and how many are in right for every node.
             and when (left Node + 1 == K) means current node is the kth smallest element.

             Time = O(N^2).
  
             2) Recursive but using two more variable one is keep count of visited node and second one
             is ans just like here. 

             Time = O(N)

             3) To store the value in array. O(N) + O(N) (frequently deleted and modified).
             If we could add a count field in the BST node class, it will take O(n) time when 
             we calculate the count value for the whole tree, but after that, 
             it will take O(logn) time when insert/delete a node or calculate the kth smallest element.

             4) O(H) H = height of BST. -> Early Stop Version of [2]. (Coded Here).


*/


class Solution {
public:

    void inorder(TreeNode* root, int &count, int k, int &ans) {

        if(root == nullptr)
            return;

        if(count <= k)
            inorder(root->left, count, k, ans);

        if(count <= k) {

            if(count == k) ans = root -> val;

            count++;

            inorder(root -> right, count, k, ans);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 1, ans = -1;
        inorder(root, count, k, ans);
        return ans;
    }
};