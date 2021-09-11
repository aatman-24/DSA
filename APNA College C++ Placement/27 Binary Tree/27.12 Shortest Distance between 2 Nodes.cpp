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
Question : 27.12 Shortest Distance between 2 Nodes
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


Node* LCA(Node* root, int n1, int n2) {

    if(root == NULL)
        return NULL;

    if(root -> data == n1 || root -> data == n2)
        return root;

    Node* LeftLCA = LCA(root -> left, n1, n2);
    Node* rightLCA = LCA(root -> right, n1, n2);

    if(LeftLCA && rightLCA)
        return root;

    if(LeftLCA)
        return LeftLCA;

    return rightLCA;
}

int findDist(Node* root, int key, int dist) {

    if(root == NULL) {
        return -1;
    }
    if(root -> data == key)
        return dist;

    int left = findDist(root -> left, key, dist+1);
    if(left != -1) {
        return left;
    }
    return findDist(root -> right, key, dist+1);
}



int distBwNodes(Node *root, int n1, int n2) {

    Node* lca = LCA(root, n1, n2);

    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);

    return d1 + d2;
}

    
int main() {

    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);

    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    // cout << LCA(root,4,7) -> data << endl;
    cout << distBwNodes(root, 7, 7) << endl;
}

