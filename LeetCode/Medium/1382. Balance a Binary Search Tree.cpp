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

Question: 1382. Balance a Binary Search Tree
Topic : Hashing
Problems : https://leetcode.com/problems/balance-a-binary-search-tree/

==============================> Explanation <=============================================

- Using Preorder make sorted Array. Then construct Tree again from that sorted Array.

start = 0, end = n.
That's why when (start == end) we return nullptr already end index  is coverd.

==============================> Apporach and Time Complexity <=============================================
2) Hashing:
Time: O(N)
Space: O(N)

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

    vector<TreeNode*> sortedArray;
    

    TreeNode* constructTree(int start, int end) {

        if(start >= end)
            return nullptr;

        int mid = (start + end) / 2;  // Avoid Int Flow = start + (end - start)/2

        TreeNode* root = sortedArray[mid];
        
        // Here check I passed mid... which is already covered. So when start == end we return null.
        root -> left =  constructTree(start, mid);
        root -> right = constructTree(mid+1, end);

        return root;
    }


    void preorder(TreeNode* root, vector<TreeNode*> &sortedArray) {
        if(root == nullptr)
            return;
        
        preorder(root -> left, sortedArray);
        
        sortedArray.push_back(root);
        
        preorder(root->right, sortedArray);
    }


    TreeNode* balanceBST(TreeNode* root) {

        preorder(root, sortedArray);

        int start = 0, end = sortedArray.size();

        return constructTree(start, end);
    }
};