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

Question : 24. Swap Nodes in Pairs
Topic : Linked List
Problems : https://leetcode.com/problems/swap-nodes-in-pairs/
*/

// Three Pointer. prev, curr, next || recursive looks good.

/*
Edge Case: 


*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    
    void swapNode(ListNode* &prev, ListNode* &curr, ListNode* &curr_nxt) {
        curr -> next = curr_nxt -> next;
        prev -> next = curr_nxt;
        curr_nxt -> next = curr;
    }

    // Iterative O(N) - O(1)
    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL) return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
    
        ListNode* prev = dummy;
        ListNode* curr = head;
        ListNode* curr_nxt = curr -> next;

        while(curr_nxt != NULL) {

            swapNode(prev, curr, curr_nxt);

            if(curr -> next == NULL || curr -> next -> next == NULL) break;

            prev = curr;
            curr = curr -> next;
            curr_nxt = curr -> next;
        }
        return dummy -> next;
    }
    
    // Recursive O(N) - O(1)
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }

        ListNode* n = head -> next;
        head -> next = swapPairs(head -> next -> next);
        n -> next = head;
        return n;
     }
};