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

Question : 148. Sort List
Topic : LinkedList, mergesort
Problems : https://leetcode.com/problems/sort-list/
*/

/*
Edge Case: 
    when we return single node at a time we need to set the next pointer to NULL.

    bcz In merge both LL must be in node1....NULL and node2....NULL.

*/

/*
Explanation: 
    // Perfect Merge Sort:
    Traced the second LL head using (low,mid,end).
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

    // Find length of LL.
   int length(ListNode* head) {
        int n = 0;
        while(head) {
            head = head -> next;
            n++;
        }
        return n;
    }

    // Merge sorted LL and return head
    ListNode* merge(ListNode* head1, ListNode* head2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* dummyHead = dummy;

        while(head1 != NULL && head2 != NULL) {

            if(head1 -> val <= head2 -> val) {
                dummy -> next = head1;
                head1 = head1-> next;
            }
            else {
                dummy -> next = head2;
                head2 = head2 -> next;
            }
            dummy = dummy -> next;
        }

        if(head1) {
            dummy -> next = head1;
        }
        
        if(head2) {
            dummy -> next = head2;
        }
        
        return dummyHead -> next;
    }

    // find (mid+1)th node of LL.
    ListNode* findHead2(ListNode* head, int low, int mid) {

        while(low <= mid) {
            head = head -> next;
            low++;
        }
        
        return head;
    }

    // O(NlogN) - O(1)
    ListNode* mergeSort(ListNode* &head, int low, int end) {

        if(low < end) {

            int mid = (low + end)/ 2;

            ListNode* head2 = findHead2(head, low, mid);
            ListNode* head1 = mergeSort(head, low, mid);
            head2 = mergeSort(head2, mid+1, end);
            head = merge(head1, head2);
        }
        else {
            head -> next = NULL;
        }
        return head;

    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        int end = length(head);
        return mergeSort(head, 0, end-1);
    }
};