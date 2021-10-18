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

Question: 650. 2 Keys Keyboard
Topic : Top-Down Pattern=Bounded Knapsack
Problems : https://leetcode.com/problems/2-keys-keyboard/

==============================> Explanation <=============================================
- Dp variant = Unbounded Knapsack,
- Either copy the current one and paste it. Or don't copy the current one just paste the previous copied.
==============================> Apporach and Time Complexity <=============================================

1) Brute Force Pattern=Bounded Knapsack
Time: O(N*M)
Space: O(N*M)

*/



class Solution {
public:
    
    int t[1001][1001];

    int minSteps(int cur, int prev, int n) {

        if(cur > n)
            return 10000;

        if(cur == n)
            return 0;

        if(t[cur][prev] != -1)
            return t[cur][prev];

        // copy and paste current one.
        // copy the current one and paste it. cur = cur + cur, prev = cur.
        int copy = 2 + minSteps(cur+cur, cur, n);

        // don't copy current one.
        // just paste the previous copied items, cur = cur + prev, prev = prev.
        int paste = 1 + minSteps(cur+prev, prev, n);

        return t[cur][prev] = min(copy, paste);
    }


    int minSteps(int n) {
        if(n == 1 || n == 0)
            return 0;
        
        memset(t, -1, sizeof(t));

        // cur = Single A
        // prev =  Copied single A.
        return minSteps(1, 1, n) + 1;    // +1 for prev...
    }
};