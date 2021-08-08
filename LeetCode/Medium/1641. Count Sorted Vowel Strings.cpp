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

Question : 1641. Count Sorted Vowel Strings
Topic : Number
Problems : https://leetcode.com/problems/count-sorted-vowel-strings/
*/

class Solution {
public:

    int cnt = 0;

    void backtrack(int index, int n) {
        if(n == 0) {
            cnt++;
            return;
        }
        for(int i = index; i >= 0; i--) {
            backtrack(i, n-1);
        }
    }

    // backtracking
    int countVowelStrings(int n) {
         cnt = 0;
         backtrack(4, n);
         return cnt;   
    }




    // O(N) simple if n = 1 a,e,i,o,u 
    // if N > 1 then we replace a with previous all character which is started with a.
    // like example....
    // aa, ae, ai...
    // here we can replace first aa with aaa, aae, aai, aao..
    // same for ae we can replac with aee, aei.. (only start from current and move forward only).

    // O(N)
    int countVowelStrings(int n) {
    int a,e,i,o,u;
        a = e = i = o = u = 1;
        while(n > 1) {
            a = (a + e + i + o + u);
            e = (e + i + o + u);
            i = (i + o + u);
            o = (o + u);
            u = (u);
            n--;
        }
        return a + e + i + o + u;
    }
};

