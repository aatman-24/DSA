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
Question : 27.6 Count and Sum of Nodes
*/

/*
==============================> Edge Case <=============================================
No Edge Case
*/

/*
==============================> Explanation <=============================================


*/

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(struct Node* root) {
    if(root == NULL)
        return;
    cout << root -> data << ' ';
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(struct Node* root) {
    if(root == NULL)
        return;
    inorder(root -> left);
    cout << root -> data << ' ';
    inorder(root -> right);
}

void postorder(struct Node* root) {
    if(root == NULL)
        return;
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << ' ';
}


int countNodes(Node* root) {
    if(root == NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int sumNodes(Node* root) {
    if(root == NULL)
        return 0;

    return sumNodes(root->left) + sumNodes(root->right) + root -> data;

}


int main() {

    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);

    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    cout << countNodes(root) << endl;
    cout << sumNodes(root) << endl;

}

