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

Question : 817. Linked List Components
Topic : LinkedList
Problems : https://leetcode.com/problems/linked-list-components/
*/

/*
Edge Case: 

*/

/*
Explanation: Here you just need to count how many subsets are there which is consecutive
in LL from the nums array. 
- single node is also consecutive.
- if two nodes are consecutive count only once.


- In short we need to count tail of consecutive subsets in LL.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}

class Solution {
public:

    int numComponents(ListNode* head, vector<int>& nums) {

        ListNode* tmp = head;
        int n = 0;
        while(tmp) {
            tmp = tmp -> next;
            n++;
        }

        vector<int> mark(n,0);
        for(auto num : nums) {
            mark[num] = 1;
        }

        int i = 0, cnt = 0;
        while(head != NULL) {

            if(mark[head->val]) {
                while(head != NULL && mark[head->val]) {
                    head = head -> next;
                }
                cnt++;
            }
            else {
                head = head -> next;
            }
        }

        return cnt;

    }

};  