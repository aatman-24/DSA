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

Question :  106. Construct Binary Tree from Inorder and Postorder Traversal
Topic : Tree
Problems : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

==============================> Explanation <=============================================
Same. Follow up - Construct Binary Tree from Preorder and Inorder Traversal
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

    int findIndexOfElement(vector<int> &arr, int low, int high, int target) {

        for(int i = low; i <= high; i++) {
            if(arr[i] == target)
                return i;
        }
        return -1;
    }


    TreeNode* helper(vector<int>& postorder, vector<int>& inorder, int low, int high, int &index) {

        if(low > high) {
            return NULL;
        }

        int ele = postorder[index--];

        int elementAt = findIndexOfElement(inorder, low, high, ele);

        TreeNode* right = helper(postorder, inorder, elementAt+1, high, index);
        TreeNode* left = helper(postorder, inorder, low, elementAt-1, index);
        
        TreeNode* curr = new TreeNode(ele);
        curr -> left = left;
        curr -> right = right;

        return curr;
    }


    // O(N^2) - O(1)
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size()-1;
        return helper(postorder, inorder, 0, postorder.size()-1, index);
    }
};