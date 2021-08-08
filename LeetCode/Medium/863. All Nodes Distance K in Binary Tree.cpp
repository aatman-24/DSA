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

Question : 863. All Nodes Distance K in Binary Tree
Topic :BT
Problems : https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

==============================> Explanation <=============================================
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/discuss/143798/1ms-beat-100-simple-Java-dfs-with(without)-hashmap-including-explanation


Apna college Video:

Brute Force = O(N^2) Search for every node to the k distance target is available or not.

DFS + Map = must check using above algorithm.
- First search the target node and store the node -> distance into the map.
- Then perform DFS and all the nodes whose distance is k add to the result.

Optimized = Apna College Check. 

*/


/*
==============================> Edge Case <=============================================


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void subtreeNodesDistanceAtK(TreeNode* root, int k, vector<int> &ans) {

        if(root == nullptr || k < 0)
            return;

        if(k == 0) {
            ans.push_back(root->val);
            return;
        }

        subtreeNodesDistanceAtK(root->left, k-1, ans);
        subtreeNodesDistanceAtK(root->right, k-1, ans);

    }


    int nodesDistanceAtK(TreeNode* root, TreeNode* target, int k, vector<int> &ans) {

        if(root == nullptr)
            return -1;

        if(root == target) {
            subtreeNodesDistanceAtK(root, k, ans);
            return 0;
        }

        int ld = nodesDistanceAtK(root -> left, target, k, ans);
        if(ld != -1) {
            if(ld + 1 == k) {
                ans.push_back(root -> val);
            }
            else {
                subtreeNodesDistanceAtK(root->right, k - ld - 1 - 1, ans);
            }
            return 1+ld;
        }

        int rd = nodesDistanceAtK(root -> right, target, k, ans);
        if(rd != -1) {
            if(rd + 1 == k) {
                ans.push_back(root -> val);
            }
            else {
                subtreeNodesDistanceAtK(root->left, k - rd - 1 - 1, ans);
            }
            return 1+rd;
        }
        return -1;
    }



    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> ans;
        int dist = nodesDistanceAtK(root, target, k, ans);
        return ans;
    }
};


// Java DFS + Map.
class Solution {
    
    Map<TreeNode, Integer> map = new HashMap<>();
        
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        List<Integer> res = new LinkedList<>();
        find(root, target);
        dfs(root, target, K, map.get(root), res);
        return res;
    }
    
    // find target node first and store the distance in that path that we could use it later directly
    private int find(TreeNode root, TreeNode target) {
        if (root == null) return -1;
        if (root == target) {
            map.put(root, 0);
            return 0;
        }
        int left = find(root.left, target);
        if (left >= 0) {
            map.put(root, left + 1);
            return left + 1;
        }
        int right = find(root.right, target);
        if (right >= 0) {
            map.put(root, right + 1);
            return right + 1;
        }
        return -1;
    }
    
    private void dfs(TreeNode root, TreeNode target, int K, int length, List<Integer> res) {
        if (root == null) return;
        if (map.containsKey(root)) length = map.get(root);
        if (length == K) res.add(root.val);
        dfs(root.left, target, K, length + 1, res);
        dfs(root.right, target, K, length + 1, res);
    }
}
