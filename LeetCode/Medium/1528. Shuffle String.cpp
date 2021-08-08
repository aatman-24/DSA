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

Question : 1528. Shuffle String
Topic : String
Problems : https://leetcode.com/problems/shuffle-string/

/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================


*/


class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string res = s;
        for(int i = 0; i < indices.size(); i++){
            res[indices[i]] = s[i];
        }     
        return res;
    }
};