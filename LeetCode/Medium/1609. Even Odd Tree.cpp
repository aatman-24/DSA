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

Question: 1609. Even Odd Tree
Topic : Tree, Level Order Traversal, BFS, DFS
Problems : https://leetcode.com/problems/even-odd-tree/

==============================> Explanation <=============================================
- DFS(IN-B):
--> We can create a one 2D vector and store the all value of node using DFS(left->root->right).
--> And then checking that any level violate the condition or not.
--> Doing that We visit all the nodes and after checking the condition which will take more
time. We can optimized it.


- BFS(IN-O):
- Simple Level Order Traversal. During Level We check it holds condition or not. So If not
we can return from that rathar than visiting all unnecessary nodes.

==============================> Apporach and Time Complexity <=============================================

1) DFS:
Time: O(N)
Space: O(N)(Aux) + O(N)(storing the value)

2) BFS:
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


bool isEvenOddTree(TreeNode* root) {

    queue<TreeNode*> q;
    q.push(root);

    int level = 0;

    while(!q.empty()) {

        int size = q.size();
        

        // Based on level previous value is initalized. Using that we don't have
        // to make separate case for the first value of level.
        int previous = level % 2 ? INT_MAX : INT_MIN;

        for(int i = 0; i < size; i++) {

            TreeNode* node = q.front(); q.pop();

            if(level % 2) {

                // Should be in strictly decreasing order. And Value must be even.
                if((node -> val % 2 == 1) || node -> val >= previous)
                    return false;
            }
            else {

                // Should be in strictly increasing order.Value must be odd.
                if((node -> val % 2 == 0) || (node -> val <= previous))
                    return false;
            }

            previous = node -> val;

            if(node -> left)
                q.push(node -> left);

            if(node -> right)
                q.push(node -> right);
        }

        level++;
    }

    return true;
}
};