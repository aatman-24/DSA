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

Question : 141. Linked List Cycle
Topic : LinkedList, Cycle Detection, Floyd Cycle 
Problems : https://leetcode.com/problems/linked-list-cycle/
*/

/*
Edge Case: head == NULL or head -> next == NULL then there is no cycle.
*/


class Solution {
public:

    // Method 1 : Hashing O(N) - O(N)
    // Traverse the LL and add complete node into LL not only value. If before reaching at the end
    // LL if you find any node in map then there is cycle.


    // Method 2 : Floyd Cycle Dectection O(N)-O(1)
    bool hasCycle(ListNode *head) {

        if(head == NULL || head -> next == NULL) 
            return false;
        
        ListNode *slow = head;
        ListNode *fast = head;

        
        do {
            slow = slow -> next;
            fast = fast -> next -> next;
        } while(fast != NULL && fast -> next != NULL && slow != fast);

        return fast == slow;

    }
};