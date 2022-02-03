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

Question : 82. Remove Duplicates from Sorted List II
Topic : LinkedLIst
Problems : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

==============================> Explanation <=============================================

Using three pointer we can remove all the duplicate.

- prev points to the last unique element.
- curr points to next element to visit.
- Runner pointer helps to avoid all duplicate.


We use two for loop... Reason is after removing all duplicate for single value.. might be follow
other duplicates.

Exa...

1 -> 2(p) -> 3(c) -> 3(n) -> 3 -> 4 -> 4 -> 5 [duplicate for 3]

1 -> 2(p) -> 3 -> 3 -> 3 -> 4(c) -> 4(n) -> 5 [duplicate for 4]

1 -> 2(p) -> 3 -> 3 -> 3 -> 4 -> 4 -> 5(c)



==============================> Apporach and Time Complexity <=============================================

1) LinkedList
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
            
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* dummny = new ListNode(-1111);
        dummny -> next = head;

        ListNode* prev = dummny;
        ListNode* curr = head;
        ListNode* runner = head -> next;


        while(curr != nullptr) {

            // cur and runner value is same... 
            while(runner != nullptr && curr->val == runner->val) {                  // 1 -> 2(p) -> 3(c) -> 3(n) -> 3 -> 4 -> 4 -> 5
                        
                // cur points to the next to the duplicate.. and runner points to the curr->Next.
                while(runner != nullptr && curr->val == runner->val) {              // 1 -> 2(p) -> 3 -> 3 -> 3 -> 4(c) -> 4(n) -> 5
                    runner = runner->next;
                }
                
                curr = runner;
                if(curr != nullptr) runner = curr -> next;  
            }

            // update three pointer.
            prev->next = curr;
            prev = curr;
            curr = runner;
            if(curr != nullptr) runner = curr->next;
        }


        return dummny->next;
    }

};