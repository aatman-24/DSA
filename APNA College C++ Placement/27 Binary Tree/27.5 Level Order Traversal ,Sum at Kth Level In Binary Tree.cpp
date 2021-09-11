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
Question : 27.5 Level Order Traversal ,Sum at Kth Level In Binary Tree 
*/

/*
==============================> Edge Case <=============================================
No Edge Case
*/

/*
==============================> Explanation <=============================================
same as BFS. But needs to handle case to know how the level is finish.
For that NULL is used at last for every level.

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


void printLevelOrder(Node* root) {

    if(root == NULL)
        return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* node = q.front();
        q.pop();
        if(node != NULL) {
            cout << node -> data << ' ';
            if(node -> left)
                q.push(node->left);
            if(node -> right)
                q.push(node->right);
        }
        else if(!q.empty()) {
            q.push(NULL);
        }
    }

}


int sumAtKLevel(Node* root, int k) {
    if(root == NULL)
        return -1;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;

    while(!q.empty()) {

        Node* node = q.front();
        q.pop();

        if(node != NULL) {
            if(level == k) {
                sum += node -> data;
            }

            if(node -> left)
                q.push(node -> left);

            if(node -> right)
                q.push(node -> right);
        }
        else if(!q.empty()) {
            q.push(NULL);
            level++;
        }
        else if(level > k) {
            return sum;
        }
    }
    return sum;
}


int main() {

    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);

    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);


    printLevelOrder(root);
    cout << endl;
    cout << sumAtKLevel(root, 1) << endl;


}

