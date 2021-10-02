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

Question: 1894. Find the Student that Will Replace the Chalk
Topic : prefixSum
Problems :  https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/

==============================> Explanation <=============================================
1) Brute Force: Just perform what is given... simulate the process.

2) Prefix Sum Or Simple Logic:

- First perform the SUM(arr).

Cut off the extra rounds -> rem = k % SUM(arr). Because at each round the SUM(arr) chalks is deducted from
the current Chalk so we can directly jump to the last stage(or round) when current chalk is less than
any of chalk[i].

==============================> Apporach and Time Complexity <=============================================

2) Prefix Sum:
Time:O(N)
Space:O(1)

*/


class Solution {
public:

    int chalkReplacer(vector<int>& chalk, int k) {

        long sum = 0;
        for(int num: chalk)
            sum += num;

        // cut the rounds.
        long rem = k % sum;
        long i = 0;

        while(rem >= chalk[i]) {
            rem -= chalk[i];
            i++;
        }

        return i;
    }
};