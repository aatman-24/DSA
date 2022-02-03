#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007
#define eps 1e-6

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

Question : 455. Assign Cookies
Topic : Two Pointer
Problems : https://leetcode.com/problems/assign-cookies/

==============================> Explanation <=============================================

- Greedy Apporach.
- Sort both the array in ascending order.
- We start from the largest g[i], if it is consumed by the largest s[j]
then we assign that s[j] -> g[i]. Otherwise we leave it.

==============================> Apporach and Time Complexity <=============================================

1) Two Pointer
Time: O(NlogN + MlogM)
Space: O(1)

*/


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = g.size() - 1, j = s.size() - 1, count = 0;
        
        while(i >= 0 && j >= 0) {

            if(g[i] <= s[j]) {
                i--; j--;
                count++;
            }
            else{
                i--;
            }
        }

        return count;
    }
};


