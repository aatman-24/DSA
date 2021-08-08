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

Question :  1302. Deepest Leaves Sum
Topic : Tree
Problems : https://leetcode.com/problems/deepest-leaves-sum/

==============================> Explanation <=============================================


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

    // O(N) + O(N) -> Level Travesal Using Queue.
    int deepestLeavesSum(TreeNode* root) {

        int sum = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int size = q.size();

            // Every Level Reset the sum. So for the last level it is not going to reset
            // so it is over answer.
            
            sum = 0;

            for(int i = 0; i < size; i++) {

                TreeNode* curr = q.front(); q.pop();

                sum += curr -> val;

                if(curr -> left)
                    q.push(curr -> left);

                if(curr -> right)
                    q.push(curr -> right);
            }
        }

        return sum;

    }



    int getHeight(TreeNode* root) {
        if(root == nullptr) return 0;
        return max(getHeight(root->left), getHeight(root -> right)) + 1;
    }


    int getLastLevelSum(TreeNode* root, int highestLevel, int currentLevel) {

        if(root == nullptr) {
            return 0;
        }
        
        if(currentLevel == highestLevel) {
            return root->val;
        }
    
        int leftSum = getLastLevelSum(root -> left, highestLevel, currentLevel+1);
        int rightSum = getLastLevelSum(root -> right, highestLevel, currentLevel+1);

        return leftSum + rightSum;
    }


    // Two Pass 2 DFS + First get Height Of the tree.
    int deepestLeavesSum(TreeNode* root) {

        int highestLevel = getHeight(root);

        return getLastLevelSum(root, highestLevel, 1);
    }






    // DFS Single Pass.
    // currLevel -> Denote the current level of tree.
    // deepestLevel -> Denote the deepestLevel until we reach in tree.
    // curSum -> Denote the sum of deepestLevel node.
    void helper(TreeNode* root, int currLevel, int &deepestLevel, int &curSum) {

        if(root == NULL) 
            return;

        // Reset the sum and increase the value of deepestLevel.
        if(currLevel > deepestLevel) {
            curSum = root -> val;
            deepestLevel = currLevel;
        }

        // Add sum if we reach at the deepestLevel.
        else if (currLevel == deepestLevel) {
            curSum += root -> val;
        }

        helper(root->left, currLevel+1, deepestLevel, curSum);
        helper(root->right, currLevel+1, deepestLevel, curSum);
    }

    // single pass - 1 DFS O(N).
    int deepestLeavesSum(TreeNode* root) {
        int curSum = 0, deepestLevel = INT_MIN;
        helper(root, 0, deepestLevel, curSum);
        return curSum;
    }

};