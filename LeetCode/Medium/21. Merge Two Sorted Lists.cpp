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

Question : 21. Merge Two Sorted Lists
Topic : Linked List
Problems : https://leetcode.com/problems/merge-two-sorted-lists/
*/



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tmp1 = head1;
        ListNode* tmp2 = head2;

        ListNode* tmp3 = dummy;

        while(tmp2 != NULL && tmp1 != NULL) {
            if(tmp1 -> val < tmp2 -> val) {
                tmp3 -> next = tmp1;
                tmp1 = tmp1 -> next;
            }
            else {
                tmp3 -> next = tmp2;
                tmp2 = tmp2 -> next;
            }
            tmp3 = tmp3 -> next;
        }

        // Remaining linkelist directly added
        if(tmp1 != NULL) {
            tmp3 -> next = tmp1;
        }

        if(tmp2 != NULL) {
            tmp3 -> next = tmp2;
        }

        dummy = dummy -> next;
        return dummy;
    }
};