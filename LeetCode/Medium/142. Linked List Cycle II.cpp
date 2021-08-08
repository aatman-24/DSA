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

Question : 142. Linked List Cycle II
Topic : LinkedList
Problems : https://leetcode.com/problems/linked-list-cycle-ii/
*/

/*
Edge Case: 

head == NULL or head -> next == NULL return NULL;

*/

class Solution {
public:

    // Method-1 : Hashing O(N) - O(N)
    // Hash the complete nodd. and check every time whether we found
    // node or not.


    // Method-2 : Floyd-Cycle Detection O(N) - O(1)

    ListNode* detectCycle(ListNode *head) {

        if(head == NULL || head -> next == NULL) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;

        while(fast->next && fast->next->next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) {
                while(slow != entry) {
                    slow = slow -> next;
                    entry = entry -> next;
                }
                return entry;
            }
        }
        return NULL;

    }

    // Same Do-while
    ListNode* detectCycle(ListNode *head) {

        if(head == NULL || head -> next == NULL) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;

        do {
            slow = slow -> next;
            fast = fast -> next -> next;
        } while(fast != NULL && fast -> next != NULL && slow != fast);

        if(slow != fast) return NULL;

        fast = head;
        while(fast != slow) { // check here
            slow = slow -> next;
            fast = fast -> next;
        }
        
        return slow; // check here
    }


};