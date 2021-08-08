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

Question : 160. Intersection of Two Linked Lists
Topic : Linked List
Problems : https://leetcode.com/problems/intersection-of-two-linked-lists/
*/



// Definition for singly-linked list.
 struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
    
public:
    
    // Brute: O(N^M) - O(1)
    // Take one node in one LL and check this node is in other LL.

    // Better: O(N+M) - O(N)
    // Use the Map. Traverse any LL and store its node address into map. After that traverse 
    // other LL and check whether address is in map or not.


    int length(ListNode* &head) {
        ListNode* tmp = head;
        int cnt = 0;
        while(tmp != NULL) {
            tmp = tmp -> next;
            cnt++;
        }
        return cnt;
    }
    
    // Optimal1: O(M+N) - O(1) [length code]
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        
        if(head1 == NULL || head2 == NULL) return NULL;

        int l1 = length(head1);
        int l2 = length(head2);

        ListNode* tmp1;
        ListNode* tmp2;

        if(l1 > l2) {
            tmp1 = head1;
            tmp2 = head2;
        }
        else {
            tmp1 = head2;
            tmp2 = head1;
        }

        int d = abs(l1 - l2);
        
        while(d) {
            tmp1 = tmp1 -> next;
            d--;
        }

        while(tmp1 != NULL && tmp2 != NULL) {

            if(tmp1 == tmp2) {
                return tmp1;
            }

            tmp1 = tmp1 -> next;
            tmp2 = tmp2 -> next;
        }

        return NULL;
    }



  
    // https://www.youtube.com/watch?v=u4FWXfgS8jw&list=PLgUwDviBIf0r47RKH7fdWN54AbWFgGuii&index=7
    // if we traverse both pointer same length then differnce is going to remove automatic from the
    // the biggest LL.
    

    // Optimal1: O(M+N) - O(1) [Precise code] 
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        if(head1 == NULL || head2 == NULL) return NULL;

        ListNode *a = head1;
        ListNode *b = head2;


        while(a != b) {

            a = (a == NULL) ? head2 : a -> next;
            b = (b == NULL) ? head1 : b -> next; 
        }

        return a;
    }




};