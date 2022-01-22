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

Question: 257. Binary Tree Paths
Topic : Binary tree path
Problems : https://leetcode.com/problems/binary-tree-paths/

==============================> Explanation <=============================================

- simple tree path problem.

==============================> Apporach and Time Complexity <=============================================

1) DFS
Time: O(N)
Space: O(H)(Aux) (Height of Binary Tree)

*/

class Solution {

    public:

    void dfs(TreeNode* root, string cur_path, vector<string> &ans) {
        
        // Leaf node is defined as both child as null.
        if(root->left == nullptr && root->right == nullptr) {
            cur_path += to_string(root->val);
            ans.push_back(cur_path);
            return;
        }   

        cur_path += to_string(root->val) + "->";

        if(root->left)
            dfs(root->left, cur_path, ans);

        if(root->right)
            dfs(root->right, cur_path, ans);
    }


    vector<string> binaryTreePaths(TreeNode* root) {
        
        if(root == nullptr)
            return {};

        vector<string> answer;

        string cur_path;

        dfs(root, cur_path, answer);

        return answer;
    }
};