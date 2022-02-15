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

Question : 501. Find Mode in Binary Search Tree
Topic : Tree Traversal.
Problems : https://leetcode.com/problems/find-mode-in-binary-search-tree/

==============================> Explanation <=============================================

Beautiful Problem...

- Find the most frquent element in the tree. Easy!

But when the most frequent element are more than one, then we need to think about it.

1st Use Extra Space:

    - we use the map<element, freq>.

    - last we find max freq

    - find all element which have max freq.


2nd Without using Extra Space:


    - First things first, without using extra space we can not memorize the most frquent element with count. So it is
    not possible in one traversal.

    - We need two traveral.

        - find the frquency of most times occured element.

        - find all the element, which frequency is matched with - (1).


It is only possible with inorder -> left -> root -> right.

Why?

WE first visit all the left nodes, root, right nodes.

if(root->val == root->right->val)
    then all the left subtree of root->right is must be root->val or nullptr.


  
        2
       / \
     2     2
          /
        2
       / 
      2

So all the 2 element visit same time.

It can not other values.

        2
       / \
     2     2
          /
        2
       / 
      1

    [NO BST]


    
Optimized 2nd Apporach:

    - Using recursion, we have aux space.

    - Using morris inorder traversal, we can remove it.

==============================> Apporach and Time Complexity <=============================================

1) Stack
Time: Each Operation: O(1), O(1)
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
    
    unordered_map<int,int> mp;

    void findModes(TreeNode* root) {

        if(root == nullptr)
            return;

       findModes(root->left);
       findModes(root->right);

       if(mp.count(root->val))
            mp[root->val]++;
        else
            mp[root->val] = 1;
    
    }


    vector<int> findMode(TreeNode* root) {

        findModes(root);

        // find max frequency.
        int max_freq = 0;
        for(auto it: mp) {
            if(it.second > max_freq)
                max_freq = it.second;
        }
        
        // find all element with max frequency.
        vector<int> ans;
        for(auto it: mp) {
            if(it.second == max_freq) {
                ans.push_back(it.first);
            }
        }


        return ans;
    }
};










class Solution {

public:
    
    // keep track of previous element with cur Count.
    int prev = INT_MIN;
    int count = 0;

    // keep track of maximum frequency.
    int modes = 0;
    

    void inorder(TreeNode* root) {
        
        if(root == nullptr)
            return;

        inorder(root->left);

        // prev and current not same. update the prev and count.
        if(root->val != prev) {
            prev = root->val;
            count=1;
        }
        else {
            count++;
        }

         modes = max(modes, count);

        inorder(root->right);
    }


    // second round, we store all the maximum element into the answer.
    void inorder(TreeNode* root, vector<int> &ans) {
        
        if(root == nullptr)
            return;

        inorder(root->left, ans);

        if(root->val != prev) {
            prev = root->val;
            count = 1;
        }
        else {
            count++;
        }

        if(count == modes) {
            ans.push_back(root->val);
        }

        inorder(root->right, ans);
    }


    vector<int> findMode(TreeNode* root) {

        inorder(root);

        vector<int> ans;

        count = 0;
        prev = INT_MIN;
        inorder(root, ans);

        return ans;
    }
};




// same above solution, replace two inorder function into single one.
class Solution {

public:
    
    int cur = INT_MIN;
    bool modesCounted = false;
    int modes = 0;
    int count = 0;
    vector<int> ans;

    void handleValue(int val) {
        
        if(val != cur) {
            cur = val;
            count=1;
        }
        else {
            count++;
        }

         modes = max(modes, count);
         if(modesCounted && modes == count) {
            ans.push_back(val);
         }

    }


    void inorder(TreeNode* root) {
        
        if(root == nullptr)
            return;

        inorder(root->left);

        handleValue(root->val);

        inorder(root->right);
    }



    vector<int> findMode(TreeNode* root) {

        inorder(root);

        modesCounted = true;

        count = 0;
        cur = INT_MIN;
        inorder(root);

        return ans;
    }
};




// We can use the inorder morris traversal for O(1) space, eliminate the recurisve space also.

class Solution {

public:
    
    int cur = INT_MIN;
    bool modesCounted = false;
    int modes = 0;
    int count = 0;
    vector<int> ans;

    void handleValue(int val) {
        
        if(val != cur) {
            cur = val;
            count=1;
        }
        else {
            count++;
        }

         modes = max(modes, count);

         if(modesCounted && modes == count) {
            ans.push_back(val);
         }

    }


    void inorder(TreeNode* root) {

        TreeNode* node = root; 

        while(node != nullptr) {

            if(node -> left == nullptr) {

                handleValue(node->val);

                node = node -> right;
            }
            else {

                TreeNode* prev = node -> left;

                while(prev->right != nullptr && prev->right != node) {
                    prev = prev->right;
                }   

                // visit first time, make link, go left
                if(prev->right == nullptr) {
                    prev->right = node;
                    node = node->left;
                }

                // second time, go right
                else {
                    prev->right = nullptr;
                    handleValue(node->val);
                    node = node->right;
                }

            }
        }

    }



    vector<int> findMode(TreeNode* root) {

        inorder(root);

        modesCounted = true;

        count = 0;
        cur = INT_MIN;
        inorder(root);

        return ans;
    }
};