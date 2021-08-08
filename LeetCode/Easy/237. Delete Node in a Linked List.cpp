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

Question : 237. Delete Node in a Linked List
Topic : LinkedList, Logic
Problems : https://leetcode.com/problems/delete-node-in-a-linked-list/
*/

/*
Explanation: That is not possible to delete some node without head refernce. This is 
dump question but intersting.


How you delete node ?

you not deleting node but value inside node is going to change. you copy next node value 
inside given node and delete next node and pointing to the next to next node.

*/


class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node -> next -> val;
        node -> next = node -> next -> next;
    }
};