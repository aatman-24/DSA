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

Question: 589. N-ary Tree Preorder Traversal
Topic : Tree Traversal
Problems : https://leetcode.com/problems/n-ary-tree-preorder-traversal/

==============================> Explanation <=============================================

- Simple Preorder Traversal, but here For N-ary Tree not for Binary. But logic is same root -> left -> right. 

==============================> Apporach and Time Complexity <=============================================

1) Tree Traversal
Time: O(N)
Space: O(N)(Aux)

*/


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

    void preorder(Node* root, vector<int> &ans) {
        
        if(root == nullptr)
            return;

        ans.push_back(root -> val);
        
        for(auto it: root->children) {
            preorder(it, ans); 
        }

    }

    vector<int> preorder(Node* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};