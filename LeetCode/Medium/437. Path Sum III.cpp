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

Question : 437. Path Sum III
Topic :BT
Problems : https://leetcode.com/problems/path-sum-iii/

==============================> Explanation <=============================================
very IMP question.

- count subarray with given target sum using prefix sum is very IMP. see that one also.

- Here same concept is used using dfs. Which path it goes we use prefix array logic.
And when we backtrack from the node we remove it prefix sum which end current node
from them map so for other node which is not into path, not use the prefix sum of it.

solution from: Cracking Coding Interview. Check there.

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

    int countPathsWithSumFromNode(TreeNode* root, int curSum, int targetSum) {

        if(root == nullptr)
            return 0;

        curSum += root -> val;
        
        int totalPath = 0;
        
        if(curSum == targetSum)
            totalPath++;

        totalPath += countPathsWithSumFromNode(root->left, curSum, targetSum);
        totalPath += countPathsWithSumFromNode(root->right, curSum, targetSum);
        
        return totalPath;
    }

    // Brute Foce - O(NlogN).
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root == nullptr) return 0;
        
        int pathFromRoot = countPathsWithSumFromNode(root, 0, targetSum);
        
        int pathsOnLeft = pathSum(root -> left, targetSum);
        int pathOnRight = pathSum(root -> right, targetSum);

        return pathFromRoot + pathsOnLeft + pathOnRight ;
    }
};



class Solution {
public:


    void incrementHashTable(int currentSum, map<int,int> &mp, int delta) {

        int newCount = mp.find(currentSum) == mp.end() ? delta : mp[currentSum] + delta;
        if(newCount == 0) {
            mp.erase(currentSum);
        }
        else {
            mp[currentSum] = newCount;
        }

    }


    int pathSum(TreeNode* root, int currentSum, int targetSum, map<int,int> &mp) {

        if(root == NULL)
            return 0;

        // Add into the current Sum.
        currentSum += root->val;

        // count total Path usign prefix sum.
        int totalPath;
        if(mp.find(currentSum - targetSum) == mp.end())
            totalPath = 0;
        else
            totalPath = mp[currentSum - targetSum];

        // If current node is the tail..
        if(currentSum == targetSum)
            totalPath++;
        

        incrementHashTable(currentSum, mp, 1);

        totalPath += pathSum(root->left, currentSum, targetSum, mp);
        totalPath += pathSum(root->right, currentSum, targetSum, mp);

        // Here we remove the currentSum from the map due to the current root node.
        // Becasue when we backtrack the others nodes did not need to consider the currentSum
        // as prefix sum.
        incrementHashTable(currentSum, mp, -1);
        
        return totalPath;
    }

    // O(N) + O(logN) [prefix sum array variation]
    int pathSum(TreeNode* root, int targetSum){
        map<int, int> mp;
        return pathSum(root, 0, targetSum, mp);
    }

};
