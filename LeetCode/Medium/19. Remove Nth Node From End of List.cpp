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

Question : 19. Remove Nth Node From End of List
Topic : Linked List, Two Pointer
Problems : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/



/*
Edge Case: 
Added Dummy node for linkedlist head is deleted at a time useful.
*/


class Solution {
public:

    // O(N) - Two Pass
    ListNode* removeNthFromEnd(ListNode* head, int k) {

        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;

        ListNode* tmp = head;

        int length = 0;
        while(tmp != NULL) {
            tmp = tmp -> next;
            length++;
        }

        int cnt = 0;
        tmp = dummy;

        while(tmp != NULL) {
            if(cnt == length - k) {
                break;
            }
            tmp = tmp -> next;
            cnt++;
        }
        
        tmp -> next = tmp -> next -> next;
        return dummy->next;
    }

    // O(N) - Single Pass
    ListNode* removeNthFromEnd(ListNode* head, int k) {

        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        
        ListNode* slow = dummy;
        ListNode* fast = head;
        
        for(int i = 1; i <= k; i++) fast = fast -> next;

        while(fast != NULL) {
            fast = fast -> next;
            slow = slow -> next;
        }
        
        slow -> next = slow -> next -> next;
        return dummy->next;
    }

};