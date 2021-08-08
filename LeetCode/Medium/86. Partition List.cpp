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
    
    // Method 1: O(N^2) - O(1)
    // Simple find the node which value is less than x and again 
    // traverse the LL from the front at find the place.


    // Method 2: O(N) - O(1) Two Pointer
    ListNode* partition(ListNode* head, int x) {

        ListNode* dummy = new ListNode(INT_MIN);
        dummy -> next = head;

        ListNode* p1 = dummy;
        ListNode* prev = dummy;
        ListNode* tmp = head;

        while(tmp != NULL) {

            if(tmp -> val < x) {
                prev -> next = tmp -> next;
                tmp -> next = p1 -> next;
                p1 -> next = tmp;
                p1 = p1 -> next;
            }

            prev = tmp;
            tmp = tmp -> next;
        }
        return dummy -> next;
    }
};