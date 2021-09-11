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
Question : 27.9 Height Balanced Binary Tree 
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

int height(Node* root) {
    if(root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

// O(N^2)
bool isBalanced(Node* root) {
    if(root == NULL)
        return true;

    if(isBalanced(root->left) == false) 
        return false;

    if(isBalanced(root->right) == false)
        return false;

    int lh = height(root -> left);
    int rh = height(root -> right);

    if(abs(lh - rh) <= 1)
        return true;
    else 
        return false;
}

bool isBalanced(Node* root, int &height) {
    if(root == NULL)
        return true;

    int lh = 0, rh = 0;
    if(isBalanced(root -> left, lh) == false)
        return false;
    if(isBalanced(root -> right, rh) == false)
        return false;

    height = max(lh, rh) + 1;

    if(abs(lh - rh) <= 1)
        return true;
    else 
        return false;

}


int main() {

    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);

    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    cout << isBalanced(root) << endl;

    int height = 0;
    cout << isBalanced(root, height) << endl;
}


