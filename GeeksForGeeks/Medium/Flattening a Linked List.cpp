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

Question : Flattening a Linked List
Topic : LinkedList
Problems :https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#
*/

/*
Edge Case: 

*/

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;
    
    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
    
};

Node* mergeLL(Node* &head1, Node* &head2) {

    Node* dummy = new Node(-1);
    Node* nwHead = dummy;

    Node* tmp1 = head1;
    Node* tmp2 = head2;

    while(tmp1 != NULL && tmp2 != NULL) {
        if(tmp1 -> data <= tmp2 -> data) {
            dummy -> bottom = tmp1;
            tmp1 = tmp1 -> bottom; 
        }
        else{
            dummy -> bottom = tmp2;
            tmp2 = tmp2 -> bottom;
        }
        dummy = dummy -> bottom;
    }

    if(tmp1 != NULL) {
        dummy -> bottom = tmp1;
    }
    if(tmp2 != NULL) {
        dummy -> bottom = tmp2;
    }
    return nwHead -> bottom;
}


// Iterative O(N*M) - O(1) [but it take more time compare to recursive because
// ideal solution is to start from the bottom so that minimum comparison occurs.]
Node *flatten(Node *root){

    if(root -> next == NULL) return root;
    Node* nxt;

    Node* dummy = root;
    root = root -> next;

    while(root != NULL) {
        if(root != NULL) nxt = root -> next;
        dummy = mergeLL(dummy, root);
        root = nxt;
    }
    return dummy;
}

// Recursive O(N*M) - O(1)
Node* flatten(Node *root) {

    if(root == NULL || root -> next == NULL)
        return root;

    // recursive call untill [root, root->next, null]
    root -> next = flatten(root -> next);

    // merge two LL and point to the root.
    root = mergeLL(root, root -> next);

    // sorted LL head
    return root;
}

    