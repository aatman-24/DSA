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

Question: 206. Reverse Linked List
Topic : LinkedList
Problems : https://leetcode.com/problems/reverse-linked-list/

==============================> Explanation <=============================================
Iterative: Using Three pointer.

Recursive: Using Two Pointer.

==============================> Apporach and Time Complexity <=============================================
1) Two Pointer Recursive
Time: O(N)
Space: O(N)(Aux)

2) Iterative
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
    ListNode* reverseList(ListNode* head) {
        
        ListNode *prev = nullptr, *curr = head;

        while(curr != nullptr) {

            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};


// Recursive.
class Solution {
public:
    ListNode* reverseList(ListNode* curr, ListNode* prev=nullptr) {
            
            // base case. same as iterative.
            if(curr == nullptr)
                return prev;

            ListNode* newHead = reverseList(curr->next, curr);

            // update the pointer link.
            curr->next = prev;

            return newHead;
    }
};