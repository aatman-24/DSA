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

Question : 1669. Merge In Between Linked Lists
Topic : Linked List
Problems : https://leetcode.com/problems/merge-in-between-linked-lists/
*/

/*
Edge Case:
Here a >= 1 given in this problem then there is no edge case.
But Here I also included when a == 0 then we need to use dummy node at front of list.
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        ListNode* dummy = new ListNode(-1);
        dummy -> next = list1;
        list1 = dummy;
  
        int count = -1;
        ListNode* list1_End;
        while(count <= b) {
            if(count == a - 1) {
                list1_End = list1;
            }
            list1 = list1 -> next;
            count++;
        }
        list1_End -> next = list2;

        while(list2 -> next != NULL) {
            list2 = list2 -> next;
        } 

        list2 -> next = list1; // list1 is represent b+1 node.
        return dummy->next;
    }
};