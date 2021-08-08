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

Question : 234. Palindrome Linked List
Topic : LinkedList, Middle of LL, Reverse of LL
Problems : https://leetcode.com/problems/palindrome-linked-list/
*/


/*
Edge Case: 

Finding middle element:
    when odd length LL need to stop tmp -> next = NULL
    when even length LL need to stop when tmp -> next -> next == NULL



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

    static ListNode* reverseLinkedList(ListNode* &head) {

        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nxt;

        while(curr != NULL) {

            nxt = curr -> next;
            curr -> next = prev;

            prev = curr;
            curr = nxt;
        }

        return prev;
    }
    
    // Method 1: Pure Logic 
    // Find Middle element of LL + rerverse right side of middle + check palindrome using two pointer
    // + again reverse right side of middle so linked list not going to change

    // O(N/2+N/2+N/2+N/2) = O(2N) = O(N).
    bool isPalindrome(ListNode* head) {

        if(head == NULL || head -> next == NULL) 
            return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast -> next != NULL && fast -> next -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* middle = slow;

        slow->next = reverseLinkedList(slow->next);
        slow = slow -> next;

        ListNode* tmp = head;
        bool flag = true;

        while(slow != NULL && flag) {
            flag = tmp -> val == slow -> val;
            tmp = tmp -> next;
            slow = slow -> next;
        }

        middle -> next = reverseLinkedList(middle -> next);
        return flag;
    }



    // METHOD 2: Recursion + Two Pointer =  O(N) - O(1)
    // Move One pointer to the last element and used recursion stack. I think that is simliar to 
    // externally used stack.
    bool checkRecursive(ListNode* &forward, ListNode* backward) {

        if(backward == NULL) return true;

        bool flag  = checkRecursive(forward, backward->next);

        if(flag == false) return false;
        flag = forward -> val == backward -> val;
        forward = forward -> next;
        return flag;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* forward = head;
        return checkRecursive(forward, head);
    }
    
};