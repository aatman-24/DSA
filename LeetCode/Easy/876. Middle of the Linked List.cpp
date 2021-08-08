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

Question : 876. Middle of the Linked List
Topic : LinkedList, Two Pointer
Problems : https://leetcode.com/problems/middle-of-the-linked-list/
*/

/*
Edge Case: 

*/


class Solution {
public:

    // O(N) - 2 pass
    /*
        n = linkedlist length
        ceil(n/2) is middle one.
    */



    // O(N) - 1 pass (Two Pointer)
    ListNode* middleNode(ListNode* head) {
        
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;

    }
};