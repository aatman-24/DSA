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



int maxPathSumUtil(Node* root, int &ans) {
    if(root == NULL)
        return 0;

    int left = maxPathSumUtil(root -> left, ans);
    int right = maxPathSumUtil(root -> right, ans);


    int nodeMax = max({root->data, root->data+left, root->data+right, root->data+right+left});
    ans = max(ans, nodeMax);

    // Bcz when left+right value is encounterd into ans at time we can not add 
    // ancestor value into path. For including ancestor we must add either left or
    // right or not any one into path.(not both)
    int singlePathSum = max({root->data, root->data+left, root->data+right});
    return singlePathSum;
}




int maxPathSum(Node* root) {
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;

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

