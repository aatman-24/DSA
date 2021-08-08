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
d
/*
==============================> Description <=============================================

Question : 649. Dota2 Senate
Topic : Greedy
Problems : https://leetcode.com/problems/dota2-senate/
==============================> Explanation <=============================================
- Greedily we terminate the next opposite party member to vote. This process run until only one
party element remain.

- After the first iteration we don't get result we have to repetely have to perform the same step.
That's why we use the Queue or (string swap).

*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:

    // O(N) = O(N) + O(N/2) + O(N/4) .... Space = O(N) (Extra String)
    string predictPartyVictory(string senate) {
        int count = 0, len = 0;
        // When the length of senate doesn't decrease, the game is over.
        while (senate.size() != len) {
            string s;
            len = senate.size();
            for (int i = 0; i < len; i++) {
                if (senate[i] == 'R') {
                    if (count++ >= 0) s += 'R';
                }
                else if (senate[i] == 'D') {
                    if (count-- <= 0) s += 'D';
                }
            }  
            swap(s, senate);
        }
        if (senate[0] == 'R') 
            return "Radiant";
        else 
            return "Dire";
    }

    // O(N) = O(N) + O(N/2) + O(N/4) .... Space = O(N) (Two Queue)
    string predictPartyVictory(string senate) {
        queue<int> q1, q2;
        int n = senate.length();
        for(int i = 0; i<n; i++)
            (senate[i] == 'R')?q1.push(i):q2.push(i);
        while(!q1.empty() && !q2.empty()){
            int r_index = q1.front(), d_index = q2.front();
            q1.pop(), q2.pop();
            (r_index < d_index)?q1.push(r_index + n):q2.push(d_index + n);
        }
        return (q1.size() > q2.size())? "Radiant" : "Dire";
    }
};

