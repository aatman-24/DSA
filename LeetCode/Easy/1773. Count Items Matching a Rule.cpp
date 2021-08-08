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

Question : 1773. Count Items Matching a Rule
Topic : String
Problems : https://leetcode.com/problems/count-items-matching-a-rule/
*/


// O(N)
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {

            int index;
            if(ruleKey == "type") index = 0;
            else if(ruleKey == "color") index = 1;
            else index  = 2;

            int n = items.size();

            int cnt = 0;
            REP(i,n) {
                if(items[i][index] == ruleValue) cnt++;
            }
            return cnt;
        }

};