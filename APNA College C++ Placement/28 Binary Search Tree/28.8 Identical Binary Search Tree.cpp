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
Question : 28.8 Identical Binary Search Tree

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

// O(min(N,M))
bool isIdentical(Node* root1, Node* root2) {

    if(root1 == NULL && root2 == NULL){
        return true;
    }
    // when one of is null and second one is not null. combined with above condition.
    else if(root1 == NULL || root2 == NULL) {
        return false;
    }
    else {
        bool dataSame = (root1 -> data == root2 -> data);
        bool leftValid = isIdentical(root1 -> left, root2 -> left);
        bool rightValid = isIdentical(root1 -> right, root2 -> right);

        if(dataSame && leftValid && rightValid)
            return true;
        else
            return false;
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





    Node* root2 = new Node(4);
    root2 -> left = new Node(2);
    root2 -> right = new Node(6);

    root2 -> left -> left = new Node(1);
    root2 -> left -> right = new Node(3);


    // root2 -> right -> left = new Node(5);
    root2 -> right -> right = new Node(7);

    cout << isIdentical(root, root2) << endl;

}
 

 