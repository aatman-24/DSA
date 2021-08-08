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

Question : 1019. Next Greater Node In Linked List
Topic : Linked List, Stack
Problems : https://leetcode.com/problems/next-greater-node-in-linked-list/
*/

// Raining Trapping water stack method 

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
    vector<int> nextLargerNodes(ListNode* head) {

        stack<int> st;
        stack<int> index;

        int n = 0;
        ListNode* tmp = head;
        while(tmp != NULL) {
            tmp = tmp -> next;
            n++;
        }

        vector<int> res(n,0);
        tmp = head;

        int cnt = 0;
        while(tmp != NULL) {

            while(st.empty() || (tmp != NULL && tmp -> val <= st.top())) {
                st.push(tmp -> val);
                index.push(cnt++);
                tmp = tmp -> next;
            }
            
            if(tmp != NULL)
            {
                while(!st.empty() && st.top() < tmp -> val) {
                    res[index.top()] = tmp -> val;
                    index.pop();
                    st.pop();
                }
            }
        }
        return res;
    }
};