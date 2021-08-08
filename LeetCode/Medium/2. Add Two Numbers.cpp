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

Question : 2. Add Two Numbers
Topic : LinkedList
Problems : https://leetcode.com/problems/add-two-numbers/
*/


/*
Edge Case: At last when carry > 0 we need to add one extra node for that carry. Same as

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;

        int carry = 0, sum = 0;

        while(l1 != NULL || l2 != NULL || carry) {

            sum = carry;

            if(l1 != NULL) {
                sum += l1->val;
                l1 = l1 -> next;
            }

            if(l2 != NULL) {
                sum += l2 -> val;
                l2 = l2 -> next;
            }

            carry = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);
            dummy -> next = newNode;
            dummy = dummy -> next;  
        }

        return head -> next;

    }

};