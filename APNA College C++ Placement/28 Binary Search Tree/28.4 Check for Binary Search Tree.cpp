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
Question : 28.4 Check for Binary Search Tree
*/

/*
==============================> Edge Case <=============================================

*/
 
/*
==============================> Explanation <=============================================
just checking for given node 
node -> left -> data < node -> data  < node -> right -> data
is not right apporach. 

because if any node encounter at upper layer than its value must be greater than 
every element from its left subtree and vice versa with right subtree.


Same as previous using min-max variable we can achieve it.
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

// O(N) - O(1)
bool isBST(Node* root, Node* min=NULL, Node* max=NULL) {

    if(root == NULL)
        return true;

    if(min != NULL && root -> data <= min -> data) {
        return false;
    }

    if(max != NULL && root -> data >= max -> data) {
        return false;
    }

    bool leftValid = isBST(root -> left, min, root);
    bool rightValid = isBST(root -> right, root, max);

    return leftValid && rightValid;
}


int main()
{

    Node* root = NULL;
    root = new Node(2);
    root -> left = new Node(1);
    root -> right = new Node(3);

    if(isBST(root)) {
        cout << "Valid " << endl;
    } 
    else {
        cout << "Not Valid" << endl;
    }

    Node* root2 = NULL;
    root2 = new Node(1);
    root2 -> left = new Node(2);
    root2 -> right = new Node(3);

    if(isBST(root2)) {
        cout << "Valid " << endl;
    } 
    else {
        cout << "Not Valid" << endl;
    }

}
 

 