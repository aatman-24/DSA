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

Question : 138. Copy List with Random Pointer
Topic : LinkedList
Problems : https://leetcode.com/problems/copy-list-with-random-pointer/
*/

/*
Edge Case: 


1) When we pointing to radom pointer at a time if in old LL node->radnom == NULL then 
   we don't need to make null into the new LL it is already null as per the constructor.
   as you can not access the node->radom->next at a time.
*/
// https://www.youtube.com/watch?v=VNf6VynfpdM&list=PLgUwDviBIf0r47RKH7fdWN54AbWFgGuii&index=14

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:

    // Method 1: O(N) - O(N)
    // Using the Hashing we can do. Hash the whole node like create map<node, node> 
    // where first one is old and second one is new node.
    // Then traverse the LL again and make connection in new LL using map and new node.
    // LIke..
    // newNode = map[oldnode];
    // newNode -> next = map[oldnode->next]
    // newNode -> random = map[oldnode->random] 



    // Method 2: O(N) - O(1)
    Node* copyRandomList(Node* head) {

        Node* tmp = head;
        Node* headOfCopy = new Node(-1);
        Node* tmpCopy = headOfCopy;

        // First Step To add New Node afterward the OG node with same value
        // and make network having this new node.
        while(tmp != NULL) {

            Node* n = new Node(tmp->val);

            n -> next = tmp -> next;
            tmp -> next = n;

            tmp = n -> next;
        }


        // Point the random pointer of new node.
        tmp = head;
        while(tmp != NULL) {
            if(tmp -> random != NULL)
            {
                tmp-> next-> random = tmp -> random -> next;
            }
            tmp = tmp -> next -> next;
        }


        // Get OG LL again.
        // tmpDuplicate points to the previous node in new LL.
        tmp = head;
        while(tmp != NULL) {

            tmpDuplicate -> next = tmp -> next;
            tmpDuplicate = tmpDuplicate -> next;

            tmp -> next = tmpDuplicate -> next;
            tmp = tmp -> next;
        }

        return headOfCopy -> next;

    }

};