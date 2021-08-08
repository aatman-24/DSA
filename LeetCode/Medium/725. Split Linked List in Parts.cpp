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

Question : 725. Split Linked List in Parts
Topic : Linked List
Problems : https://leetcode.com/problems/split-linked-list-in-parts/
*/

// Simple Keep track of prev and make prev->next NULL.

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

    int length(ListNode* root) {
        int cnt = 0;
        ListNode* tmp = root;
        while(tmp != NULL) {
            tmp = tmp -> next;
            cnt++;
        }
        return cnt;
    }

    vector<ListNode*> splitListToParts(ListNode* root, int k) {
     
        int n = length(root);
        vector<ListNode*> result(k, NULL);

        int upto = n / k;
        int remain = n % k;
        int index = 0;

        ListNode* tmp = root;
        ListNode* prev = NULL;

        while(tmp != NULL) {

            result[index] = tmp;

            for(int cnt = 1; cnt <= upto; cnt++) {
                prev = tmp;
                tmp = tmp -> next;
            }
                
            if(remain > 0) {
                prev = tmp;
                tmp = tmp -> next;
                remain--;
            }

            if(prev != NULL) prev -> next = NULL;
            index++;
        }

        return result; 
    }
};