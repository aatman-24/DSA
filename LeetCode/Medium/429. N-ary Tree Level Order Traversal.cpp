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

Question: 429. N-ary Tree Level Order Traversal
Topic : Tree Traversal
Problems : https://leetcode.com/problems/n-ary-tree-level-order-traversal/

==============================> Explanation <=============================================

Simliar: 589. N-ary Tree Preorder Traversal

- Same as Binary Tree Level Order Traversal.

==============================> Apporach and Time Complexity <=============================================

1) Tree Traversal
Time: O(N)
Space: O(logN)(Aux + Height of Tree)

/*

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> ans;

        if(root == nullptr)
            return ans;

        queue<Node*> q;

        q.push(root);

        while(!q.empty()) {

            int size = q.size();
            vector<int> level;

            for(int i = 0; i < size; i++) {

                Node* node = q.front(); q.pop();
                level.push_back(node->val);
                
                for(auto it: node->children) {
                    q.push(it);
                }
            }

            ans.push_back(level);

        }

        return ans;
    }
};