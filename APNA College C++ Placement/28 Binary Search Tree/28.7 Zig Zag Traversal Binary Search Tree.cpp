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
Question : 28.7 Zig Zag Traversal Binary Search Tree

/*
==============================> Edge Case <=============================================

*/
 
/*
==============================> Explanation <=============================================
level order = queue
zig zag = 2 stack
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


void preorder(Node* root) {
    if(root == NULL)
        return;
    cout << root -> data << ' ';
    preorder(root -> left);
    preorder(root -> right);
}

void zigzagTraversal(Node* root) {
    if(root == NULL)
        return;

    stack<Node*> currLevel;
    stack<Node*> nextLevel;
    bool leftToRight = true;

    currLevel.push(root);

    while(!currLevel.empty()) {


        Node* node = currLevel.top(); currLevel.pop();

    
        if(node) {

            cout << node -> data << ' ';

            // first left and last right. (next level right first and left last)
            if(leftToRight) {

                if(node -> left) {
                    nextLevel.push(node -> left);
                }

                if(node -> right) {
                    nextLevel.push(node -> right);
                }
            }
            else {

                if(node -> right) {
                    nextLevel.push(node -> right);
                }


                if(node -> left) {
                    nextLevel.push(node -> left);
                }
            }
        }

        if(currLevel.empty()) {
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }
}


int main()
{

    Node* root = new Node(4);


    root -> left = new Node(2);
    root -> right = new Node(6);

    root -> left -> left = new Node(1);
    root -> left -> right = new Node(3);


    root -> right -> left = new Node(5);
    root -> right -> right = new Node(7);

    zigzagTraversal(root);

}
 

 