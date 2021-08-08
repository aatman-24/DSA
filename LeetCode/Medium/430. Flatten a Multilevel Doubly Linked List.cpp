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

Question : 430. Flatten a Multilevel Doubly Linked List
Topic : Doubly LinkedList
Problems : https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
*/

/*
Edge Case: 

*/

/*
Explanation: 
    Recursive solution:
    if(node -> child) then we going to flat this and return the last node of this flatten LL.
    and relink with next node.
*/

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten1(Node* node) {

        if(node->child == NULL && node -> next == NULL) 
            return node;

        while(node->next != NULL || node -> child != NULL) {

            if(node -> child != NULL) {

                Node* LastNode = flatten1(node->child);
                Node* nextNode = node -> next;

                node -> next = node -> child;
                node -> child -> prev = node;
                node -> child = NULL;

                if(nextNode != NULL) {
                    nextNode -> prev = LastNode;
                    node  = nextNode;
                }
                else {
                    node = node -> next;
                }
                LastNode -> next = nextNode;
            }
            else {
                 node  = node -> next;
            }
           
        }
        return node;
    }


    // O(N) - Total Number of Node.
    Node* flatten(Node* node) {
        if(node == NULL) return node;
        Node* LN = flatten1(node);
        return node;
    }

};