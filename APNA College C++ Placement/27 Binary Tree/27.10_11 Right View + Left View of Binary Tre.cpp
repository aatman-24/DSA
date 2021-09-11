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
Question : 27.10|11 Right View|Left View of Binary Tree 
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

void rightView(Node* root) {
    if(root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int n = q.size();

        for(int i = 0; i < n; i++) {
            Node* curr = q.front();
            q.pop();

            if(curr -> left)
                q.push(curr -> left);

            if(curr -> right)
                q.push(curr -> right);

            if(i == n - 1)
                cout << curr -> data << ' ';
        }
    }
}


void LeftView(Node* root) {
    if(root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int n = q.size();

        for(int i = 0; i < n; i++) {
            Node* curr = q.front();
            q.pop();

            if(curr -> left)
                q.push(curr -> left);

            if(curr -> right)
                q.push(curr -> right);

            if(i == 0)
                cout << curr -> data << ' ';
        }
    }
}


int main() {

    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);

    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    rightView(root);
    cout << endl;
    LeftView(root);

    
}


