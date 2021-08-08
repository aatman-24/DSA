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

Question : 25. Reverse Nodes in k-Group
Topic : LinkedList
Problems : https://leetcode.com/problems/reverse-nodes-in-k-group/
*/

/*
Edge Case: 

when the remaining node is < k. don't do anything return it.

*/

class Solution {

    int length(ListNode* head) {
        int cnt = 0;
        while(head != NULL) {
            head = head -> next;
            cnt++;
        }
        return cnt;
    }


    ListNode* reverseK(ListNode* head, int k, int n) {

        ListNode* prevptr = NULL;
        ListNode* currptr = head;
        ListNode* nextptr;

        if(n < k) return currptr;

        int cnt = 0;
        while(currptr != NULL && cnt < k) {
            nextptr = currptr -> next;
            currptr -> next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
            n--;
            cnt++;
        }

        if(nextptr != NULL) {
            head -> next = reverseK(currptr, k, n);
        }

        return prevptr;
    }

    // Recursive O(N) - O(1)
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseK(head, k, length(head));
    }






    // Iterative O(N) - O(1)
    public ListNode reverseKGroup(ListNode head, int k) {
        // Save the previous reversed pointer in prev and in wach iteration use prev.next to set the previous ptr to the current reversed.
        ListNode tempNode = new ListNode(0);
        tempNode.next = head;
        ListNode tempHead = head;
        ListNode prev = tempNode;
        while(tempHead!=null){
            // Starting of each reversed list, it will become the last after reversing
            ListNode klast = tempHead;
            int num = k;
            // Jump k 
            while(num>0 && tempHead!=null){
                tempHead = tempHead.next;
                num--;
            }
            // If cannot reverse
            if(num!=0) {
                prev.next = klast;
                break;
            }
            // start of each reversed group
            ListNode kstart = reverse(klast,k);
            
            // Use previous's next to point to curr reversed
            prev.next = kstart;
            // Set prev to current rev end.
            prev = klast; 
        }
        return tempNode.next;
        
    }
    
    // Standard reverse code
    public ListNode reverse(ListNode head, int k){
        ListNode prev = null;
        while(head!=null && k>0){
            ListNode next = head.next;
            head.next = prev;
            prev = head;
            head = next;
            k--;
        }
        return prev;
    }
    
}


