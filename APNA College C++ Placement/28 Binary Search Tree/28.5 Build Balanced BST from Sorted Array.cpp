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
Question : 28.5 Build Balanced BST from Sorted Array 
*/

/*
==============================> Edge Case <=============================================

*/
 
/*
==============================> Explanation <=============================================
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

// O(N)
Node* sortedArrayToBST(int arr[], int start, int end) {

    if(start > end)
        return NULL;

    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);

    root -> left = sortedArrayToBST(arr, start, mid - 1);
    root -> right = sortedArrayToBST(arr, mid + 1, end); 

    return root;
}


int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    Node* root = sortedArrayToBST(arr, 0, 4);
    inorder(root);
}
 

 