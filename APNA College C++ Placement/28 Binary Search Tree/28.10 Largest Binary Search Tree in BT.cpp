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
Question : 28.10 Largest Binary Search Tree in BT

/*
==============================> Edge Case <=============================================

*/
 
/*

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

struct Info{
    int size, max, min, ans;
    bool isBST;
};

Info largestBST(Node* root) {

    if(root == NULL) {
        return {0, INT_MIN, INT_MAX, 0, true};
    }


    if(root -> left == NULL && root -> right == NULL) {
        return {1, root->data, root -> data, 1, true};
    }


    Info leftInfo = largestBST(root -> left);
    Info rightInfo = largestBST(root -> right);

    Info curr;

    curr.size = (1 + leftInfo.size + rightInfo.size);

    if(leftInfo.isBST && rightInfo.isBST && leftInfo.max < root -> data && root -> data < rightInfo.min ) {
        curr.min = min(leftInfo.min, min(rightInfo.min, root -> data));
        curr.max = max(rightInfo.max, max(leftInfo.max, root -> data));

        curr.ans = curr.size;
        curr.isBST = true;

        return curr;
    }

    // Once you know that from here BST can no be form at a time 
    // you just reject min and max value update it's now not matter.
    // only matter is what is size ans parameter which will be denoted as 
    // max_size of BST from it's left and right subtree.

    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;

    return curr;
}


int main()
{

    Node* root = new Node(15);


    root -> left = new Node(20);
    root -> right = new Node(30);

    root -> left -> left = new Node(5);
    // root -> left -> right = new Node(3);

    cout << "Largest BST in BT: " << largestBST(root).ans << endl;

    return 0;
}
 

 