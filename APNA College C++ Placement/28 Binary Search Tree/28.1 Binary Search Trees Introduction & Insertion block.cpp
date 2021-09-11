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
Question : 28.1 Binary Search Trees Introduction & Insertion block 
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

void inorder(Node* root) {
    if(root == NULL) return;

    inorder(root -> left);
    cout << root -> data << ' ';
    inorder(root -> right);

}

Node* insertBST(Node *root, int val) {

    if(root == NULL) 
        return new Node(val);

    if(val < root -> data)
        root -> left = insertBST(root -> left, val);
    else 
        root -> right = insertBST(root -> right, val);

    return root;
}


int main()
{

    Node* root = NULL;
    vector<int> arr = {4,2,5,1,3,6};

    /* Binary tree
            4
           / \
          2   5
         / \   \
        1   3   6
    */

    for(int i = 0; i < arr.size(); i++)
        root = insertBST(root, arr[i]);


    inorder(root);
    cout << endl;

}
 

 