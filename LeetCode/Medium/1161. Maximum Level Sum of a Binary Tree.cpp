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

Question: 1161. Maximum Level Sum of a Binary Tree
Topic : Tree, BFS, Level Order Traversal
Problems : https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

==============================> Explanation <=============================================
- Simple Level order Traversal.

Problem can be solved using DFS also, but it is good practise solve the bfs problem using BFS and
DFS problem with DFS.

==============================> Apporach and Time Complexity <=============================================

1) BFS level Order Traversal:
Time: O(N)
Space: O(N)(Queue)

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
    int maxLevelSum(TreeNode* root) {

        int maximumSum = INT_MIN, maxSumlevel;

        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        while(!q.empty()) {
            int size = q.size();
            int sumOfLevel = 0;
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();
                sumOfLevel += node -> val;
                if(node -> left)
                    q.push(node -> left);
                if(node -> right)
                    q.push(node -> right);
            }
            if(sumOfLevel > maximumSum) {
                maximumSum = sumOfLevel;
                maxSumlevel = level;
            }
            level++;
        }

        return maxSumlevel;
    }
};