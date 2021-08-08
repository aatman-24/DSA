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

Question : 147. Insertion Sort List
Topic : LinkedList
Problems : https://leetcode.com/problems/insertion-sort-list/
*/

/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================

 
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
    ListNode* insertAtRightPlace(ListNode* newhead, ListNode* node) {

        ListNode* tmp = newhead;
        ListNode* prev;
        ListNode* nxtNode = node -> next;


        while(tmp != NULL && tmp -> val < node -> val) {
            prev = tmp;
            tmp = tmp -> next;
        }

        node -> next = tmp;
        prev -> next = node;

        return nxtNode;
    }


    // O(N^2) - O(1)
    ListNode* insertionSortList(ListNode* head) {

        if(head == NULL || head -> next == NULL) return head;

        ListNode* dummy1 = new ListNode(INT_MIN);
        ListNode* tmp;

        while(head != NULL) {
            head = insertAtRightPlace(dummy1, head);
        }

        return dummy1 -> next;
    }


    // You can optimize it more. like when nodes are 1->2->3
    // this than we can add all nodes once. 
};