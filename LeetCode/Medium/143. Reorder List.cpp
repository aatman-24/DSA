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

Question: 143. Reorder List
Topic : LinkedList, Stack
Problems :  https://leetcode.com/problems/reorder-list/

==============================> Explanation <=============================================
1) Stack Solution:
-> Go to the mid -> next Node.
-> Put after all the nodes into the stack.
-> Using stack rearrange the Nodes.

2) By Trick:
-> Go to the mid -> next Node.
-> Reverse the half(last) part of LL.
-> Rearrage the node.

Can be performed using Recursion.

==============================> Apporach and Time Complexity <=============================================

1) Stack:
Time:O(N)
Space:O(N/2)


2) Optimized No Extra Space: 
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
    
    void reorderList(ListNode* head) {


        ListNode* slow = head;
        ListNode* fast = head;
        stack<ListNode*> st;

        while(fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        slow = slow -> next;
        while(slow != nullptr) {
            st.push(slow);
            slow = slow -> next;
        }


        // Relink
        ListNode* curr = head;
        ListNode* next;
        while(!st.empty()) {

            // save the curr -> next as next pointer.
            next = curr -> next;

            // make curr -> next = st.top();
            curr -> next = st.top(); st.pop();

            // curr = curr -> next.. curr = st.top();
            curr = curr -> next;

            // st.top() -> next = next
            curr -> next = next;

            // make the curr next pointer.
            curr = next;
        }

        curr -> next = nullptr;
    }
};





class Solution {
public:
    
    ListNode* getMid(ListNode* head)
    {
        ListNode *slow,*fast;
        slow = fast = head;
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow=slow->next;
            fast = fast->next->next;
        }
        return slow;
        
    }
    
    ListNode* getReverse(ListNode* head)
    {
        ListNode *cur,*prev,*next;
        cur=head;
        prev = NULL;
        while(cur!=NULL)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        
        //  If Linked List contains less than 3 nodes then no need to do anything.
        if(head==NULL||head->next==NULL||head->next->next==NULL)
            return;
        
        /*  
            Get Middle Node
            If there is two middle node then return first Middle.
        */
        ListNode* mid = getMid(head);
        
        //  Seprate the Second Half of the LinkedList
        ListNode* secondHalf = mid->next;
        mid->next=NULL;
        
        //  Reverse the Second Half of LinkedList
        ListNode* revHalf = getReverse(secondHalf);
        
        //  Finally Merge in Required Manner
        while(head!=NULL&&revHalf!=NULL)
        {
            ListNode* temp = head->next;
            head->next=revHalf;
            revHalf=revHalf->next;
            head->next->next=temp;
            head = temp;
        }
    }
};