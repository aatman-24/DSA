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

Question: 203. Remove Linked List Elements
Topic : LinkedList, Two Pointer
Problems : https://leetcode.com/problems/remove-linked-list-elements/ 

==============================> Explanation <=============================================

- Iterative verson we keep track of prev and curr node. Relink the prev next pointer with appropriate curr node via skipping the node 
which have value equal to "val".

- Recursive version is also same,
    when we encounter node which have "val" we just return next function call result. Else we relink curr node next pointer and return that one.


==============================> Apporach and Time Complexity <=============================================
1) Iterative, Two Pointer
Time: O(N)
Space: O(1)

2) Recursive
Time: O(N)
Space: O(N)

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

    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;


        while(curr != nullptr) {
            
            // skip all the node which have val == "val".
            while(curr->val == val) {
                curr = curr->next;
            }

            // relink prev and curr.
            prev->next = curr;
            

            // move forward
            prev = curr;
            curr = curr->next;
        }
    
        return dummy->next;

    }
};


// Recursive solution.
class Solution {
public:

    ListNode* removeElements(ListNode* curr, int val) {

        // base case.
        if(curr == nullptr)
            return curr;


        // curr node which we need to remove... we directly return removeElements(curr->next). 
        if(curr->val == val)
            return removeElements(curr->next, val);

        // if curr is not contain "val" then we need to return curr node with updated next pointer.
        curr->next = removeElements(curr->next, val);

        return curr;
    }
};