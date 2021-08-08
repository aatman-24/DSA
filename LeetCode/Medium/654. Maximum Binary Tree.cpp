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

Question :  654. Maximum Binary Tree
Topic : Tree
Problems : https://leetcode.com/problems/maximum-binary-tree/

==============================> Explanation <=============================================
- We scan numbers from left to right, build the tree one node by one step;
- We use a stack to keep some (not all) tree nodes and ensure a decreasing order;
- For each number, we keep pop the stack until empty or a bigger number on top of stack; 
The bigger number (if exist, it will be still in stack) is current number's root, 
and the last popped number (if exist) is current number's left child (temporarily, 
this relationship may change in the future); Then we push current number into the stack.


Perform Dry run.


- Here Why Stack ?

- Because once we found that the st.top() is less than curr then we pop from top and until the
right condition meet. that time the last node which is popped is the left of currert node.


- And when the current is less than st.top() then we already create the link as, top() -> right = curr.
*/


/*
==============================> Edge Case <=============================================

*/

class Solution {

public:
    
    int findMaximum(vector<int> &nums, int low, int high) {

        int index = low;

        for(int i = low; i <= high; i++) {
            if(nums[index] < nums[i]) {
                index = i;
            }
        }
        return index;
    }


    TreeNode* helper(vector<int> &nums, int low, int high) {

        if(low > high) {
            return nullptr;
        }

        if(low == high) {
            return new TreeNode(nums[low]);
        }

        int maxIdx = findMaximum(nums, low, high);

        TreeNode* node = new TreeNode(nums[maxIdx]);

        node -> left = helper(nums, low, maxIdx-1);
        node -> right = helper(nums, maxIdx+1, high);

        return node;
    }

    // Brute Force.
    // O(N^2) + O(1).
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);     
    }




     // O(N) + O(N) Using Stack.
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        vector<TreeNode*> stk;

        for (int i = 0; i < nums.size(); ++i)
        {
            TreeNode* cur = new TreeNode(nums[i]);

            // All the nodes from the stack which is less than current needs to pop and
            // attack to the left of current node.
            while (!stk.empty() && stk.back()->val < nums[i])
            {
                cur->left = stk.back();
                stk.pop_back();
            }

            // If node is less than top of stack means in decreasing order then we attach the current
            // node as right child of stack top.
            if (!stk.empty())
                stk.back()->right = cur;

            // And push the current node.
            stk.push_back(cur);
        }

        // to return the front of stack we use the vector instead of stack.
        return stk.front();
    }

};