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

Question: 83. Remove Duplicates from Sorted List
Topic : LinkedList, Two Pointers
Problems : https://leetcode.com/problems/remove-duplicates-from-sorted-list/

==============================> Explanation <=============================================

- First we add the dummy node to handle the base case.
- We skip all the duplicates of curr pointer by changing the link.
- Move the curr pointer.
- This continues until the we reach at the end of linkedlist.

==============================> Apporach and Time Complexity <=============================================

1) LinkedList, Two Pointers
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
    ListNode* deleteDuplicates(ListNode* head) {
        
        // base case.
        if(head == nullptr)
            return nullptr;

        // add dummy node.
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;


        ListNode* curr = head;

        while(curr != nullptr) {

            // skip all the duplicates.
            while(curr->next != nullptr && curr->val == curr->next->val) {
                curr->next = curr->next->next;
            }

            // move the pointer.
            curr = curr->next;
        }
        
        return dummy->next;
    }
};