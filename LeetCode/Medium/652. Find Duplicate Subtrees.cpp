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

Question: 652. Find Duplicate Subtrees
Topic : Tree, Path Construction
Problems : https://leetcode.com/problems/find-duplicate-subtrees/
==============================> Explanation <=============================================
- Create a path for every node. And using map that it is already constructed or not.

==============================> Apporach and Time Complexity <=============================================

1) Tree Traversal:
Time: O(N^2)
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


    map<string, TreeNode*> mp;
    map<string, TreeNode*> answer_map;

    string postorder(TreeNode* root) {

        if(root == nullptr)
            return ".";

        string lftPath = postorder(root -> left); /
        string rhtPath = postorder(root -> right);

        string currentPath = to_string(root->val);

        if(lftPath.size() > 0) {                // O(N) for  String Concatenation.
            currentPath += '#' + lftPath;
        }
        if(rhtPath.size() > 0) {
            currentPath += '#' + rhtPath;
        }
        
        if(mp.find(currentPath) != mp.end()) {
            answer_map[currentPath] = root; 
        }
        else {
           mp[currentPath] = root; 
        }
    
        return currentPath;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        postorder(root);    // total Call = O(N) And Each call take O(N)(Inside Call)

        vector<TreeNode*> answer;
        for(auto it: answer_map) {
            answer.push_back(it.second);
        }

        return answer;
    }
};