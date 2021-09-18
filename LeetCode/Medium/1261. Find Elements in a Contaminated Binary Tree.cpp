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

Question: 1261. Find Elements in a Contaminated Binary Tree
Topic : Tree, DFS
Problems : https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/
==============================> Explanation <=============================================
- DFS(IN-B):
- Create Tree using idx and then find the target for query. O(N) - O(N).

Optimized:
- While Creating the Tree keep track of available element into the set. So query time
it will take O(logN).

More Optimized:
- Using Binary String Generation.
https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/discuss/431229/Python-Special-Way-for-find()-without-HashSet-O(1)-Space-O(logn)-Time

==============================> Apporach and Time Complexity <=============================================

1) DFS:
Time: Create -> O(N), Find -> O(N)
Space: O(N)(Aux)

2) DFS + SET:
Time: Create -> O(N), Find -> O(log(Max(Target, Height)))
Space: O(N)(Set) + O(N)(Aux)

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

class FindElements {
    
public:

    TreeNode* root;

    FindElements(TreeNode* root) {
        this->root = root;
        startNumbering(root, 0);        
    }
    
    void startNumbering(TreeNode* root, int idx) {
        if(root == nullptr)
            return;
        root->val = idx;
        startNumbering(root -> left, 2*idx+1);
        startNumbering(root -> right, 2*idx+2);
    }

    bool find(TreeNode* root, int target) {

        if(root == nullptr)
            return false;

        if(root->val == target)
            return true;

        bool foundOnleft = find(root ->left, target);
        if(foundOnleft)
            return true;

        return find(root -> right, target);
    }


    bool find(int target) {
        return find(root, target);       
    }
};
