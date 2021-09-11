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
Question : 27.13 Flatten a Binary Tree in preorder
*/

/*
==============================> Edge Case <=============================================

*/

/*
==============================> Explanation <=============================================


*/


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node* root) {
    if(root == NULL)
        return ;
    cout << root -> data << ' ';
    preorder(root -> left);
    preorder(root -> right);
}


void flatten(Node *root) {

    if(root == NULL || (root -> left == NULL && root -> right == NULL)) 
        return;

    if(root -> left != NULL) {

        flatten(root -> left);

        Node* temp = root -> right;
        root -> right = root -> left;
        root -> left = NULL;

        Node* t = root -> right;
        while(t -> right != NULL) {
            t = t -> right;
        }
        t -> right = temp;
    }

    flatten(root -> right);
}



int main() {

    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);

    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    flatten(root);
    preorder(root);

}

