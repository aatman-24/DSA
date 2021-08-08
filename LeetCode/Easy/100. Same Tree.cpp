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

Question :  100. Same Tree
Topic : Tree
Problems : https://leetcode.com/problems/same-tree/

==============================> Explanation <=============================================
- Using AnyTravesal Method.

*/


/*
==============================> Edge Case <=============================================

*/

class Solution {
public:


    // O(N) - O(height).
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if(p == nullptr || q == nullptr) {
           return p == q;
       } 
        
        if(p -> val == q -> val) {
            bool left = isSameTree(p->left, q -> left);
            if(left) {
                bool right = isSameTree(p->right, q->right);
                return right;
            }
        }
        
        return false;
        
    }
};