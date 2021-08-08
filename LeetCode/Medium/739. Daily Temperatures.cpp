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

Question : 739. Daily Temperatures
Topic : Stack
Problems : https://leetcode.com/problems/daily-temperatures/
*/


/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================
Same as Stock Span Period problem.
*/


class Solution {
    
public:


    // O(N) - O(N)
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        vector<int> ans(n,0);
        stack<ii> st;
        int i = 0;

        while(i < n) {
            if(st.empty() || temperatures[st.top().first] > temperatures[i] ) {
                st.push({i,0});
            }
            else {
                while(!st.empty() && temperatures[st.top().first] < temperatures[i]) {

                    ii pp = st.top(); st.pop();
                    pp.second += 1;
                    ans[pp.first] = pp.second;
                    
                    if(!st.empty()) {
                        st.top().second += pp.second;
                    }
                }
                st.push({i,0});
            }
            i++;
        }
        return ans;
    }  
};