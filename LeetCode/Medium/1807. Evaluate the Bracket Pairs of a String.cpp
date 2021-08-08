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

Question : 1807. Evaluate the Bracket Pairs of a String
Topic : String
Problems : https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/

*/


class Solution {
public:
string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string, string> mp;
        string nw;

        REP(i,knowledge.size()) {
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        int i = 0, n = s.size();
        string res = "";
        while(i < n) {

            if(s[i] == '(') {
                i++;

                nw = "";
                while(s[i] != ')') {
                    nw += s[i];
                    i++;
                }

                if(mp.find(nw) != mp.end()) {
                    res += mp[nw];
                }
                else {
                    res += '?';
                }

            }
            else {
                res += s[i];
            }
            i++;
        }
        return res;
    }
};