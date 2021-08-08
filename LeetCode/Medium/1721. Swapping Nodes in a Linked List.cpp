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

Question : 1721. Swapping Nodes in a Linked List
Topic : Linked List
Problems : https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
*/

/*
Edge Case:
Using dummy node at front. No Edge Case.
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
    int length(ListNode* &head) {
        int count = 1;
        ListNode* tmp = head;
        while(tmp -> next != NULL) {
            tmp = tmp -> next;
            count++;
        }
        return count;
    }

    void swapNeighbourNode(ListNode* &prevA, ListNode* &A, ListNode* &B) {
        A -> next = B -> next;
        prevA -> next = B;
        B -> next = A;
    }

    ListNode* swapNodes(ListNode* &head, int k) {

        ListNode* prevA;
        ListNode* prevB;
        ListNode* A;
        ListNode* B;

        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        head = dummy;

        int n = length(head);
        k = min(k, n - k);

        ListNode* tmp = head;
        int cnt = 0;
        while(cnt < n) {
            if(cnt == k - 1) {
                prevA = tmp;
            } 
            if(cnt == k) {
                A = tmp;
            }
            if(cnt == (n - k - 1)) {
                prevB = tmp;
            }
            if(cnt == n - k) {
                B = tmp;
            }
            tmp = tmp -> next;
            cnt++;
        }

        if(prevB == A) {
            swapNeighbourNode(prevA, A, B);
        }
        else {
            tmp = A -> next;

            A -> next = B -> next;
            prevB -> next = A;

            B -> next = tmp;
            prevA-> next = B;
        }
        return dummy -> next;
    }

};