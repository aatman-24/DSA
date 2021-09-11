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
Question : 32.4 - Vertical Order Print 

/*
==============================> Explanation <=============================================
- We used distance from the root as key of the map and value as root->data. And
traverse all the tree and store root->data into map.
*/

/*
==============================> Edge Case <=============================================

*/
 


struct Node {
    Node *left, *right;
    int data;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void InorderTraverse(Node* root, int H, map<int, vector<int>> &mp) {
    if(root == NULL)
        return;    
    InorderTraverse(root -> left, H-1, mp);
    mp[H].push_back(root -> data);
    InorderTraverse(root -> right, H+1, mp);
}


void PrintVerticalOrder(Node* root) {
    map<int, vector<int>> mp;
    InorderTraverse(root, 0, mp);

    cout << "vertical Order" << endl;

    for(auto ii : mp) {
        cout << "distance is = " << ii.first << " Node are: ";
        for(int node: ii.second) {
            cout << node << ' ';
        }
        cout << endl;
    }
}


int main() {

    struct Node *root = new Node(10);
    root -> left = new Node(7);
    root -> right = new Node(4);

    root -> left -> left = new Node(3);
    root -> left -> right = new Node(11);

    root -> right -> left = new Node(14);
    root -> right -> right = new Node(6);

    PrintVerticalOrder(root);

    return 0;
}