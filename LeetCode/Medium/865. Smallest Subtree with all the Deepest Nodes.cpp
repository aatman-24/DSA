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

Question: 865. Smallest Subtree with all the Deepest Nodes
Topic : Binary Tree, LCA
Problems : https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
==============================> Explanation <=============================================
- Problem can be solved into two parts:

Find the deepest Node. And after that find the LCA of that deepest Node. If deepest
node is single node then return it.


1) Depth + LCA:
- First find the max_depth which is can be used to find deepest Node and then same
time we perform LCA.

2) BFS + LCA:
- So when performing the level order traversal just keep track of leftMost and
righMost Node. Because Finding LCA of them is result.

3) DFS + Depth(Single Pass):
- Intution is that when we hit to the max depth which is either possible,
- at leaf node. (single node)
- Or node which both child have deepest node(LCA).

same to same 1123. Lowest Common Ancestor of Deepest Leaves
==============================> Apporach and Time Complexity <=============================================

1) Depth + LCA:
Time: O(N)(Depth finding) + O(N)(LCA)
Space: O(N)(aux)

2) BFS + LCA:
Time: O(N)(Deepest Node finding) + O(N)(LCA)
Space: O(N)(Queue)

3) DFS + Depth:
Time: O(N)(single pass)
Space: O(N)(aux)

*/

class Solution {
public:
    int depth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }


    TreeNode* lca(TreeNode* root, int depth, int max_depth) {
        
        if(root == nullptr)
            return nullptr;

        if(depth == max_depth - 1)
            return root;

        TreeNode* left = lca(root -> left, depth+1, max_depth);
        TreeNode* right = lca(root -> right, depth+1, max_depth);

        if(left == nullptr)
            return right;
        else if(right == nullptr)
            return left;
        // else if(left && right)
            return root;
    }


    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

        int max_depth = depth(root);
        return lca(root, 0, max_depth);
    }
};



class Solution {
public:
    TreeNode* lca( TreeNode* root, TreeNode* p, TreeNode* q ) {
        if ( !root || root == p || root == q ) return root;
        TreeNode *left = lca( root->left, p, q );
        TreeNode *right = lca (root->right, p, q );

        return !left? right: !right? left: root;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if ( !root || !root->left && !root->right ) return root;
        TreeNode *leftMost = NULL;
        TreeNode *rightMost = NULL;
        
        queue<TreeNode*> q;
        q.push(root);
        while( !q.empty() ) {
            int levelSize = q.size();
            for(int level = 0; level < levelSize; level++ ) {
                TreeNode* node = q.front(); q.pop();
                if ( level == 0 ) leftMost = node;
                if ( level == levelSize - 1 ) rightMost = node;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                
            }
        }
        return lca( root, leftMost, rightMost );
    }
};

// Java Code.
class Solution {
    
    int deepestLevel = 0;
    TreeNode res = null;
    
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        dfs(root, 0);
        return res;
    }
    
    private int dfs(TreeNode root, int level) {
        if (root == null) return level;
        
        int leftLevel = dfs(root.left, level + 1);
        int rightLevel = dfs(root.right, level + 1);
        
        int curLevel = Math.max(leftLevel, rightLevel);
        deepestLevel = Math.max(deepestLevel, curLevel);

        // If both level is deepestlevel then either it is the leaf node or
        // the node which has both left and right child is deepestLevel.
        if (leftLevel == deepestLevel && rightLevel == deepestLevel)
            res = root;
        

        return curLevel;
    }
}