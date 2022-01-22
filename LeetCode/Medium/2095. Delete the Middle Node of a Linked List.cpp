#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007
#define eps 1e-6

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

Question: 2095. Delete the Middle Node of a Linked List
Topic : LinkedList, Two Pointer.
Problems : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

==============================> Explanation <=============================================
1) Brute Force: First got the length of LL. then try to remove the middle node which take two pass.

2) Fast and slow pointer: Single pass(already knew)

==============================> Apporach and Time Complexity <=============================================

1) Brute Force(Multipass):
Time: O(2N)
Space: O(1)

2) Two Pointer(single pass):
Time: O(N)
Space: O(1)

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
            
        // base case.
        if(head == nullptr || head -> next == nullptr)
            return nullptr;

        ListNode* dummy = new ListNode(head);
        dummy->next = head;

        ListNode *prev = dummy, *slow = head, *fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // odd length
        if(fast->next == nullptr) {
            prev->next = prev->next->next;
        }
        // even length
        else {
            slow->next = slow->next->next;
        }


        return dummy->next;
    }
};



ListNode* deleteMiddle(ListNode* head) {

    if (head->next == nullptr)
        return nullptr;
    
    // here we performed first step when we declare the pointer so
    // we don't need prev pointer.
    ListNode* slow = head, fast = head->next->next;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
    return head;
}