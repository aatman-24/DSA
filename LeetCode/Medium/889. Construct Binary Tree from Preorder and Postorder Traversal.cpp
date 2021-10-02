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

Question: 889. Construct Binary Tree from Preorder and Postorder Traversal
Topic : Hashing
Problems : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/submissions/

==============================> Explanation <=============================================
- Idea is simple,
preorder = root -> left -> right (we choose the root node)
postorder = left -> right -> root (tree construction(order) is based on this)


pre = [1,2,4,5,3,6,7]
post = [4,5,2,6,7,3,1]

First root is 1.

(4,5,2,6,7,3) is contain the left and right part. But which is left and which
is decided by the next node.

Second node which is left of 1. -> 2. (start, upto2) is left and remaining is right side.

           1
        /    \
    (4,5,2) (6,7,3)

So get position of the two we have to traverse the postorder again which take O(N).
So overall it become O(N^2).


So reduce it we use the map(position) which return the index of 2 in O(1).


==============================> Apporach and Time Complexity <=============================================
1) BruteForce: 
Time: O(N^2)
Space: O(1)

2) HashMap:
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
 
    // stored the index of root node position based on preorder(root->left->right).
    unordered_map<int,int> position;

    TreeNode* constructTree(vector<int> &preorder, int &index, int start, int end) {

        if(start > end)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[index]);

        // next root Node.
        index++;

        // For the current (start, end) index range, end points to the current root node
        // in postorder so we shrink that node.
        end--;

        if(index == preorder.size())
            return root;

        // find the next node position in postorder.
        int nextNodePosition = position[preorder[index]];

        if(start <= nextNodePosition && nextNodePosition <= end) {

            // root node in postorder is (left->right->root) so nextNodePosition holds the next root node.
            root -> left = constructTree(preorder, index, start, nextNodePosition);
            root -> right = constructTree(preorder, index, nextNodePosition + 1, end);
        }

        return root;
    }


    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

        // We store the postorder all node index so we can use later.
        for(int i = 0; i < preorder.size(); i++) { 
            position[postorder[i]] = i;
        }

        int index = 0;
        return constructTree(preorder, index, 0,  preorder.size() - 1);
    }
};