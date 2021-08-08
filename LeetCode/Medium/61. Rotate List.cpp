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

Question : 61. Rotate List
Topic : LinkedList
Problems : https://leetcode.com/problems/rotate-list/
*/

/*
Edge Case: 

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

    // Method 1:  O(N*K)
    // take k right rotation

    

    int length(ListNode* head) {
        int cnt = 0;
        while(head != NULL) {
            head = head -> next;
            cnt++;
        }
        return cnt;
    }

    // Method 2: O(N)
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head -> next == NULL) return head;

        int n = length(head);
        int cnt = n - (k % n) - 1;
        
        ListNode* tmp = head;
        while(tmp -> next != NULL) {
            tmp = tmp -> next;
        }
        tmp -> next = head;

        tmp = head;
        while(cnt != 0) {
            tmp = tmp -> next;
            cnt--;
        }

        head = tmp -> next;
        tmp -> next = NULL;
        return head;
    }
};