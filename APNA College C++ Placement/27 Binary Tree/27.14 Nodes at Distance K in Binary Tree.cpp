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
Question : 27.14 Nodes at Distance K in Binary Tree
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

void printSubtreeNodes(Node* root, int k) {
    if(root == NULL || k < 0)
        return;

    if(k == 0){
        cout << root -> data << ' ';
        return;
    }

    printSubtreeNodes(root->left, k-1);
    printSubtreeNodes(root->right, k-1);
}

int printAllNodesAtK(Node* root, Node* target, int k) {
    if(root == NULL)
        return -1;

    if(root == target){
        printSubtreeNodes(root, k);
        return 0;
    }

    int dl = printAllNodesAtK(root -> left, target, k);
    if(dl != -1) {
        if(dl + 1 == k) {
            cout << root -> data << ' ';
        }
        else {
            printSubtreeNodes(root -> right, k - dl - 2);
        }
        return 1+dl;
    }



    int dr = printAllNodesAtK(root -> left, target, k);
    if(dr != -1) {
        if(dr + 1 == k) {
            cout << root -> data << ' ';
        }
        else {
            printSubtreeNodes(root -> left, k - dr - 2);
        }
        return 1+dr;
    }

    return -1;
}


int main() {

    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);

    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);



    root -> left -> left->left = new Node(8);

    printAllNodesAtK(root, root -> left -> left, 1);

}

