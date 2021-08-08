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

Question :  99. Recover Binary Search Tree
Topic : Tree
Problems : https://leetcode.com/problems/recover-binary-search-tree/

==============================> Explanation <=============================================
1) AC Video. Using Four Pointer.

2) inorderMorrisTraversal Algorithm. Keep track of the node where we print the curr node value.

In both we keep track of some pointer. And In both two case. Node is neighbour and not neighbour.

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

    void calcPointers(TreeNode* root,TreeNode* &prev,TreeNode* &first,TreeNode* &mid,TreeNode* &last) {

        if(root == nullptr)
            return;

        calcPointers(root->left, prev, first, mid, last);

        if(prev && (prev->val) > (root->val)) {
            if(!first) {
                first = prev;
                mid = root;
            }
            else {
                last = root;
            }
        }

        prev = root;
        calcPointers(root->right, prev, first, mid, last);


    } 

    // Simple Inorder Travesal Concept is used.
    void recoverTree(TreeNode* root) {

        if(root == nullptr)
            return;

        TreeNode *prev=NULL, *first=NULL, *mid=NULL, *last=NULL;

        calcPointers(root, prev, first, mid, last);

        if(first && last) {
            swap(first->val, last->val);
        }
        else if(first && mid) {
            swap(first->val, mid->val);
        }

    }



    // Using inorderMorrisTraversal Algorithm. 
    void recoverTree(TreeNode* root) {

        TreeNode *curr = root, *tmp = nullptr;

        TreeNode *first = nullptr, *second  = nullptr, *pre = nullptr;

        while(curr != NULL) {


            // If left is null print the current node and move to the right node.
            if(curr->left == NULL) {

                if(pre != nullptr && pre->val > curr -> val) {
                    if(first == nullptr) {first = pre; second = curr;}
                    else second = curr;
                }
                pre = curr;

                curr = curr -> right;
            }


            // If left is not null.
            else {

                // Find Predecessor
                tmp = curr -> left;
                while(tmp->right!=NULL && tmp->right!=curr) {
                    tmp = tmp->right;
                }


                // When we thread the curr with predecessor.
                if(tmp->right==NULL) {

                    // put the current on right of predecessor.
                    tmp->right = curr;

                    // move to the left.
                    curr = curr -> left;
                }

                // when we unlink or get the orginal tree. Unthreadign.
                else{
                    // make predecessor as it is
                    if(pre != nullptr && pre->val > curr -> val) {
                        if(first == nullptr) {first = pre; second = curr;}
                        else second = curr;
                    }
                    pre = curr;


                    tmp->right = NULL;

                    // Move to the right side.
                    curr = curr -> right;

                }
            }   

        }

        if(first != NULL && second != NULL) {
            // swap the value.
            int tmp = first -> val;
            first -> val = second -> val;
            second -> val = tmp;
        }

    }


};