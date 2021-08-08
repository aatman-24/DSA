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

Question : 92. Reverse Linked List II
Topic : Linked List
Problems : https://leetcode.com/problems/reverse-linked-list-ii/
/*
==============================> Explanation <=============================================
leftHead -> [left -> ..... -> right] -> rightNxt
leafHead -> [right -> ...... -> left] -> rightNxt

we just change some pointer.And all LL between [left,right] gone make
reverse using three pointer.

until count <= right {

    when(cout == right) {
        curr -> next = prev; 
        leftHead -> next (left) -> next = right -> next;
        leaftHead -> next = right;
        break;
    }

    next = curr -> next;
    if(count >= left) curr -> next = prev;

    prev = curr;
    curr = next;
}

And when all LL needs to reverse for that we used dummy node to handle
head pointer case.

*/

/*
==============================> Edge Case <=============================================

*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // IN all of this condition no need to reverse anything.
        if(head == NULL ||left == right || head -> next == NULL) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        head = dummy;

        ListNode *leftHead = NULL, *curr = head, *prev = NULL, *next= NULL;

        int count = 0;
        while(count <= right) {

            if(count == left - 1){
                leftHead = curr;
            }
            else if(count == right) {
                // here leftHead -> next is left Pointer.
                leftHead -> next -> next = curr -> next;
                leftHead -> next = curr;
                curr -> next = prev;
                break;
            }
            next = curr -> next;
            if(count >= left) curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        return dummy -> next;
    }
};