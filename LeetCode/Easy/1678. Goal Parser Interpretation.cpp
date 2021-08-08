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

Question : 1678. Goal Parser Interpretation
Topic : String
Problems : https://leetcode.com/problems/goal-parser-interpretation/
*/


// O(N)
class Solution {
public:
    string interpret(string tmp) {
        int n = tmp.size();
        string nw_string = "";
        int i = 0;
        while(i < n){

            if(tmp[i] == 'G') {
                nw_string += 'G';
                i++;
            }       

            if(tmp[i] == '(') {
                if(i+1 < n && tmp[i+1] == ')') {
                    nw_string += 'o';
                    i+=2;
                }
                else {
                    nw_string += "al";
                    i += 4;
                }
            }

        }
        return nw_string;
    }
};