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

Question : 86. Partition List
Topic : LinkedList
Problems : https://leetcode.com/problems/partition-list/

==============================> Edge Case <=============================================
- CTCI Apporach:
- Create two separate LL. By rejoining the LL.
- Merge both LL. Value < x  -> value >= x.

==============================> Explanation <=============================================
1) Two Pointer
Time: O(N)
Space: O(1)
 
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
    

    ListNode* partition(ListNode* head, int x) {

        // create two separate LL.
        ListNode* head1 = new ListNode(INT_MIN);
        ListNode* head2 = new ListNode(INT_MIN);

        // tail of LL.
        ListNode* p1 = head1;
        ListNode* p2 = head2;
        ListNode* next = nullptr;

        while(head != NULL) {

            next = head -> next;
            head->next = nullptr;

            if(head -> val < x) {
               p1 -> next = head;
               p1 = head;
            }
            else {
                p2 -> next = head;
                p2 = head;
            }

            head = next;
        }

        p1->next = nullptr;
        p1->next = head2 -> next;

        return head1->next;
    }
};



class Solution {
public:
    

    // CTCI Apporach.
    ListNode* partition(ListNode* head, int x) {

        ListNode *leftHead = nullptr, *leftTail = nullptr, *rightHead = nullptr, *rightTail = nullptr;
        ListNode* next = nullptr;

        while(head != nullptr) {

            next = head -> next;
            head -> next = nullptr;

            if(head->val < x) {
                if(leftHead == nullptr) {
                    leftHead = head;
                    leftTail = head;
                }
                else {
                    leftTail -> next = head;
                    leftTail = head;
                }
            }
            else {
                if(rightHead == nullptr) {
                    rightHead = head;
                    rightTail = head;
                }
                else {
                    rightTail -> next = head;
                    rightTail = head;
                }
            }

            head = next;
        }

        if(leftHead == nullptr)
            return rightHead;

        leftTail->next=rightHead;

        return leftHead;
    }
};