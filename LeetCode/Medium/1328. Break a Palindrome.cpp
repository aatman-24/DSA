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

Question : 1328. Break a Palindrome
Topic : String
Problems : https://leetcode.com/problems/break-a-palindrome/
*/


class Solution {
public:

    int solve(string x) {   
        int mid, n = x.size();
        int index = n-1;
        if(n % 2) mid = n / 2 ;
        REP(i,n) {
            if(i == mid) continue;
            if(x[i] != 'a') {
                index = i;
                break;
            }
        }
        return index;

    }


    string breakPalindrome(string x){
        if(x.size() == 1) return "";
        int index =  solve(x);
        char indexStr = 'a';
        if(index == x.size() - 1) {
            if(x[index] == 'a') {
                    indexStr = 'a' + 1;
            }
        }

        string res = x.substr(0,index) + indexStr + x.substr(index+1, x.size());

        return res;

    }
};