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
Question : 28.11 Recover Binary Search Tree

/*
==============================> Edge Case <=============================================

*/
 
/*
==============================> Explanation <=============================================
- inorder strategy (inorder of BST is sorted)

[1 9(p)(f) 4(m) 6 3(e) 13 ] current
[1 3 4 6 9 13 ] result

Four Pointer: first mid last prv

mid = where first time root -> data < prev -> data
first = previous pointer of mid which is (prev pointer)
last = where second time root -> data < prev -> data
prev = previous pointer for given root in inorder traversal.

CASE 1: swapable nodes are not neighbour
swap(first, last) data


CASE 2: nodes are neighbour
swap(first, mid) data
- in this case last = NULL(second time root -> data < prev -> data)
this condition never occur.
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

    if(root == NULL)
        return;

    inorder(root -> left);
    cout << root -> data << ' ';
    inorder(root -> right);

}

void swap(int &a, int &b) {

    int tmp = a;
    a = b;
    b = tmp;
}

void calcPointers(Node* root, Node* &prev, Node* &first, Node* &mid, Node* &last) {

    if(root == NULL)
        return;

    calcPointers(root -> left, prev, first, mid, last);

    // if prev is not null (to avoid root of tree)
    if(prev && (root -> data) < (prev -> data)) {
        
        // first time
        if(!first) {
            first = prev;
            mid = root;
        }
        else {
            last = root;
        }
    }

    prev = root;
    calcPointers(root -> right, prev, first, mid, last);
}


void restoreBST(Node *root) {

    if(root == NULL)
        return;

    Node *prev, *first, *mid, *last;
    prev = NULL;
    first = NULL;
    mid = NULL;
    last = NULL;

    calcPointers(root, prev, first, mid, last);

    if(first && last) {
        swap((first->data), (last -> data));
    }
    else if(first && mid) {
        swap((first->data), (mid -> data));
    }

}


int main()
{
    Node* root = new Node(6);
    root -> left = new Node(9);
    root -> right = new Node(3);

    root -> left -> left = new Node(1);
    root -> left -> right = new Node(4);

    root -> right -> right = new Node(13);

    inorder(root);
    cout << endl;

    restoreBST(root);

    inorder(root);
    cout << endl;

    return 0;
}
 

 