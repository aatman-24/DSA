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

Question : 1347. Minimum Number of Steps to Make Two Strings Anagram
Topic : String
Problems : https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
*/

/*
	Record the occruance of charachater and sum it.
*/

#define A 97
// O(N)
class Solution {
public:
    int arr[30];
    
    int minSteps(string s, string t) {
        memset(arr, 0, sizeof(arr));

        int n = s.size();
        REP(i,n) arr[int(s[i]) - A] += 1;

        REP(i,n) 
            if(arr[int(t[i])- A] > 0) arr[int(t[i]) - A] -= 1;

        return accumulate(arr, arr+30, 0);
    }
};