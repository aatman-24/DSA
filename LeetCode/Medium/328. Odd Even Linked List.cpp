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

Question : 328. Odd Even Linked List
Topic : Linked List
Problems : https://leetcode.com/problems/odd-even-linked-list/
*/

/*
Edge Case:
1) head == NULL
2) head->next == NULL
3) odd length linked list last odd -> next == NULL
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:

    ListNode* oddEvenList(ListNode* head) {
        
    if(head == NULL || head-> next == NULL) {
        return head;
    }
        
    ListNode* odd = head;
    ListNode* even = odd -> next;
    ListNode* evenHead = even;

        while(odd -> next != NULL && even -> next != NULL) {
            odd -> next = even -> next;
            odd = odd -> next;

            if(odd -> next != NULL) {
                even -> next = odd -> next;
                even = even -> next;
            }
        }
        odd -> next = evenHead; 
        even -> next = NULL;
        return head;
    }

};