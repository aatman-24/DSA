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

Question : 450. Delete Node in a BST
Topic :BT
Problems : https://leetcode.com/problems/delete-node-in-a-bst/

==============================> Explanation <=============================================
- Both solution Same.
- I used parent node and always try to connect parent with deletedNode childs if it is.


Hanlde Four Condition:
- if no child of node return null.
- if left child return left
- if right chidl return right
- if both child,

    - Either find ancestor from left tree or right tree and change its value with root and
    recursively delete the last node.

    - In short find any left or right ancesetor of deleted node swap it(best is to swap value)
    and delete ancesetor.

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

    TreeNode* search(TreeNode* root, TreeNode* &parent, int key) {

        if(root == nullptr || root -> val == key)
            return root;

        parent = root;
        
        if(root -> val < key) {
            return search(root->right, parent, key);
        }

        return search(root->left, parent, key);
    }



    TreeNode* deleteNode(TreeNode* root, int key) {

        TreeNode* parent = NULL;
        TreeNode* node = search(root, parent, key);
        
        
        if(node != nullptr) {
                                    
            if(node -> left && node -> right) {

                
                TreeNode* temp = node -> left;
                TreeNode* parentL = node;

                while(temp != NULL && temp -> right != NULL){
                    parentL = temp;
                    temp = temp -> right;
                }

                // Swap the value of node.
                node -> val = temp -> val;
                temp -> val = key;

      
                if(node  == parentL)
                    node -> left = deleteNode(temp, key);
                else 
                    parentL -> right = deleteNode(temp, key);

            }
            else if(node -> left) {

                if(parent == NULL) return node -> left;

                if(parent -> left == node) 
                    parent -> left = node -> left;
                else 
                    parent -> right = node -> left;
            }

            else if(node -> right) {

                if(parent == NULL) return node -> right;

                if(parent -> left == node) 
                    parent -> left = node -> right;
                else 
                    parent -> right = node -> right;
            }

            else {

                if(parent == NULL) return parent;

                if(parent -> left == node)
                    parent -> left = nullptr;
                else 
                    parent -> right = nullptr;
            }
        }

        return root;
    }





    struct TreeNode* minValueNode(struct TreeNode * node)
    {
        struct TreeNode * current = node;
        while (current && current->left != NULL)
            current = current->left;
     
        return current;
    }

    // Use This Solution Looks Good.
    struct TreeNode* deleteNode(struct TreeNode* root, int key)
    {
        if (!root)
            return root;
     
        // find node to remove
        if (key < root->val)
            root->left = deleteNode(root->left, key);

        else if (key > root->val)
            root->right = deleteNode(root->right, key);

        // node found
        else
        {
            if (root->left == NULL) // no left child
            {
                struct TreeNode *temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL) // no right child
            {
                struct TreeNode *temp = root->left;
                free(root);
                return temp;
            }
            
            // if there are two children:
            // find successor, exchange values and remove the one we exchanged
            struct TreeNode * temp = minValueNode(root->right);
            root->val = temp->val;
     
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};


    