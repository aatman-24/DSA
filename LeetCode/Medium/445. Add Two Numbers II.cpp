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

Question : 445. Add Two Numbers II
Topic : Linked List
Problems : https://leetcode.com/problems/add-two-numbers-ii/
*/

// Same Idea. In singly LL if you need previous node use stack.

/*
Edge Case: 
At last when carry != 0 need to add this extra node at front.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while(l1 != NULL) {
            s1.push(l1->val);
            l1 = l1 -> next;
        }
        while(l2 != NULL) {
            s2.push(l2->val);
            l2 = l2 -> next;
        }
        ListNode* dummy = NULL;
        int carry = 0, tmp, digit;
        while(!s1.empty() || !s2.empty()) {

            tmp = carry;
            
            if(!s1.empty()) {
                tmp += s1.top();
                s1.pop();
            }

            if(!s2.empty()) {
                tmp += s2.top();
                s2.pop();
            }
            
            digit = tmp % 10;
            carry = tmp / 10;

            ListNode* tmpNode = new ListNode(digit);
            if(dummy == NULL) dummy = tmpNode;
            else {
                tmpNode -> next = dummy;
                dummy = tmpNode;
            }
        }
        
        if(carry != 0) {
            ListNode* tmpNode = new ListNode(carry);
            tmpNode -> next = dummy;
            dummy = tmpNode;
        }
        
        return dummy;
    }
}