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

Question : 173. Binary Search Tree Iterator
Topic :BT
Problems : https://leetcode.com/problems/binary-search-tree-iterator/

==============================> Explanation <=============================================
First i thought about the keeping track of current and previous pointer but it does not work here 
because we did not have to complete the inorder traversal but it is iterator so when function is called
that time we have to take decision.

- So we need to use extra space it is very clear.

- And stack is best option for any traversal preorder, inorder or postorder.\

Time = O(N)
Space = O(N) (worst case left tree or right tree)


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
class BSTIterator {
    
public:

    stack<TreeNode*> st;
    
    BSTIterator(TreeNode* root) {
        
        st.push(root);

        while(!st.empty() && st.top() -> left)
            st.push(st.top()->left);
    }
    
    // O(logN)
    int next() {

        TreeNode* node = st.top(); st.pop();
        
        if(node -> right) {
              
            st.push(node->right);

            while(!st.empty() && st.top() -> left)
                st.push(st.top()->left);
        }

        return node->val;
    }

    // O(1)
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */