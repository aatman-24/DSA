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

Question : 946. Validate Stack Sequences
Topic : Stack
Problems : https://leetcode.com/problems/validate-stack-sequences/
*/


/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================
Intuition: using both sequence we make the stack and check whether is valid or not. It is not
valid if any element push at last and given that it is pop at last at a time. That time our 
algorithm move further and reach i == pushed.size() and give last chance to pop if st.top()
== popped[j].
*/



class Solution {
public:

    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0, j = 0;

        while(i < pushed.size() && j < popped.size()) {
            st.push(pushed[i++]);
            while(j < popped.size() && !st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        return st.empty();
    }

};