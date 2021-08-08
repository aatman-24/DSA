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

Question :  95. Unique Binary Search Trees II
Topic : Tree
Problems : https://leetcode.com/problems/unique-binary-search-trees-ii/

==============================> Explanation <=============================================
- Recursion. for any node i

create all the subtreess (0, i-1) which is leftSubtrees.
create all the subtrees (i+1, n) which is rightsubtress.

Make all the combination of left with right and curr is fixed.

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


    vector<TreeNode*> constructTree(int start, int end) {

        vector<TreeNode*> trees;

        if(start > end) {
            trees.push_back(nullptr);
            return trees;
        }

        for(int i = start; i <= end; i++) {

            vector<TreeNode*> leftSubtrees = constructTree(start, i - 1);
            vector<TreeNode*> rightSubtress = constructTree(i+1, end);

            for(int j = 0; j < leftSubtrees.size(); j++) {
                TreeNode* leftNode = leftSubtrees[j];

                for(int k = 0; k < rightSubtress.size(); k++) {
                    TreeNode* rightNode = rightSubtress[k];

                    TreeNode* curr = new TreeNode(i);
                    curr -> left = leftNode;
                    curr -> right = rightNode;

                    trees.push_back(curr);
                }
            }

        }

        return trees;
    }

    // Using Catalan Number Therory Check AC Video.
    vector<TreeNode*> generateTrees(int n) {

        return constructTree(1, n);
    }
};