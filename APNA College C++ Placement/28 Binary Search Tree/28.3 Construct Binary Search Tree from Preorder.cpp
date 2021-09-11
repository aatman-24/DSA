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
Question : 28.3 Construct Binary Search Tree from Preorder
*/

/*
==============================> Edge Case <=============================================

*/
 
/*
==============================> Explanation <=============================================


*/

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printpreorder(Node* root) {
    if(root == NULL) return;

    cout << root -> data << ' ';
    printpreorder(root -> left);
    printpreorder(root -> right);

}

Node* constructBST(int preorder[], int &preorderIdx, int key, int min, int max, int n) {

    Node* root = NULL;

    if(key > min && key < max) {

        root = new Node(key);
        preorderIdx = preorderIdx + 1;

        if(preorderIdx < n) {
           root -> left = constructBST(preorder, preorderIdx, preorder[preorderIdx], min, key, n); 
        }
        if(preorderIdx < n) {
            root -> right = constructBST(preorder, preorderIdx, preorder[preorderIdx], key, max, n);
        }

    }
    return root;
}




int main()
{

    int preorder[] = {10, 2, 1, 13, 11};

    /* Binary tree
            10
           / \
          2   13
         /   /
        1   11   
    */

    int n = 5;
    int preorderIdx = 0;
    Node* root = constructBST(preorder, preorderIdx, preorder[preorderIdx], INT_MIN, INT_MAX, n);

    printpreorder(root);

}
 

 