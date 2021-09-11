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
Question : 27.15 Lowest Common Ancestor in Binary Tree
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

bool getPath(Node* root, int key, vector<int> &path) {

    if(root == NULL)
        return false;

    path.push_back(root->data);
    if(root -> data == key)
        return true;

    if(getPath(root->left, key, path) || getPath(root->right, key, path))
        return true;

    path.pop_back();
    return false;
}

// O(N) - O(1) [But overlapping is much more].
int LCA(Node* root, int n1, int n2) {
    vector<int> path1, path2;

    if(!getPath(root, n2, path1) || !getPath(root, n1, path2))
        return -1;

    int pc = 0;
    while(path1[pc] == path2[pc])
        pc++;

    return path1[pc-1];
}       

// O(N) - O(1) [single pass]
Node* LCA2(Node* root, int n1, int n2) {

    if(root == NULL)
        return NULL;

    if(root -> data == n1 || root -> data == n2) 
        return root;

    Node* leftLCA = LCA2(root -> left, n1, n2);
    Node* rightLCA = LCA2(root -> right, n1, n2);

    if(leftLCA && rightLCA) 
        return root;

    if(leftLCA != NULL)
        return leftLCA;

    return rightLCA; 
}





int main() {

    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);

    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    root -> right -> left -> left = new Node(8);


    cout << LCA(root, 7, 8) << endl;   

    cout << LCA2(root, 7, 8) -> data << endl; 
}


