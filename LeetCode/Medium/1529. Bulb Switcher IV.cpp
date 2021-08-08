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

Question : 1529. Bulb Switcher IV
Topic : String
Problems : https://leetcode.com/problems/bulb-switcher-iv/
*/


/*
IDEA : 

min number of filps required is -> length of (10101010) like this. (by observation)

so first i removed initial 0.

then if any continous "000" or "111" are same as "0" or "1" so only count for 1.



example...


10111 -> 101
101 -> 101
0010111 -> 101
11001010 -> 101010 (ans = len 6)


*/

// O(N).
class Solution {
public:
    int minFlips(string target) {

        int n = target.size();
        int i = 0;

        int cnt = 0;
        // REMOVE TRAILING ZERO
        while(target[i] == '0') i++;


        while(i < n) {

            cnt++;
            while(i< n &&  target[i] == '1') i++;

            if(i == n) break;

            cnt++;
            while(i < n && target[i] == '0') i++;
        }
        return cnt;
    }

};