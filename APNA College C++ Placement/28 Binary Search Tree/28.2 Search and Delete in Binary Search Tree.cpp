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
Question : 28.2 Search and Delete in Binary Search Tree
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

Node* searchInBST(Node* root, int key) {

    if(root == NULL)
        return NULL;

    if(root -> data == key)
        return root;

    if(root -> data > key)
        return searchInBST(root -> left, key);

    return searchInBST(root -> right, key);
}

// Here pass the root->right 
Node* inorderSuccessor(Node* root) {
    Node* curr = root;
    while(curr && curr -> left != NULL)
        curr = curr -> left;
    return curr;
}

// Here pass the root->left 
Node* inorderPredecssor(Node* root) {
    Node* curr = root;
    while(curr && curr -> right != NULL)
        curr = curr -> right;
    return curr;
}

Node* deleteInBST(Node* root, int key) {

    if(key < root -> data) {
        root -> left = deleteInBST(root -> left, key);
    }
    else if(key > root -> data) {
        root -> right = deleteInBST(root -> right, key);
    }
    else {

        // CASE 1(TWO CHILD) & 2(ONE CHILD)
        if(root -> left == NULL) {
            Node* tmp = root -> right;
            free(root);
            return tmp;
        }
        else if(root -> right == NULL) {
            Node* tmp = root -> left;
            free(root);
            return tmp;
        }

        // case 3
        Node* tmp = inorderSuccessor(root -> right);
        root -> data = tmp -> data;
        root -> right = deleteInBST(root -> right, tmp -> data);

    }
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

    if(searchInBST(root, 4) == NULL)
        cout << "Key Not found" << endl;
    else
        cout << "FOUND " << endl;


    // Inorder Sucessor
    cout << inorderSuccessor(root -> right)->data << endl;
    


    // Inorder Predecessor
    cout << inorderPredecssor(root -> left)->data << endl;


    inorder(root);
    cout << endl;
    root = deleteInBST(root, 6);
    inorder(root);
    cout << endl;

}
 

 