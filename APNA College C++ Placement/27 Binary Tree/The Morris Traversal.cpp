#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

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
Question : The Morris Traversal

/*
==============================> Explanation <=============================================
https://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html


*/


/*
==============================> Edge Case <=============================================

*/


// O(N) + O(1).
void inorderMorrisTraversal(TreeNode* root) {

    TreeNode *cur = root, *prev = nullptr;

    while(cur != NULL) {


        // If left is null print the current node and move to the right node.
        if(cur->left == NULL) {
            cout << cur -> val << endl;
            cur = cur -> right;
        }


        // If left is not null.
        else {

            // Find Predecessor
            prev = cur -> left;
            while(prev->right!=NULL && prev->right!=prev) {
                prev = prev->right;
            }


            // When we thread the curr with predecessor.
            if(prev->right==NULL) {

                // put the current on right of predecessor.
                prev->right = cur;

                // move to the left.
                cur = cur -> left;
            }

            // when we unlink or get the orginal tree. Unthreadign.
            else{
                // make predecessor as it is
                prev->right = NULL;

                // print the current node.
                cout << cur -> val << endl;

                // Move to the right side.
                cur = cur -> right;
            }
        }   

    }

}

