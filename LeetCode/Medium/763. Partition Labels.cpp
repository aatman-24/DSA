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

Question : 763. Partition Labels
Topic : two pointer, pre compute
Problems : https://leetcode.com/problems/partition-labels/
*/



#define A 97

class Solution {
public:

    // O(N) - O(1)
    vector<int> partitionLabels(string s) {

        int last[26];
        vector<int> res; 
        memset(last, 0, sizeof(last));

        for(int i = 0; i < s.size(); i++) {
                last[s[i] - A] = i;
        }

        int max_index = INT_MIN;
        int last_oc = 0;

        for(int i = 0; i < s.size() ; i++) {

            max_index = max(max_index, last[s[i]-A]);
            if(max_index == i) {
                res.push_back(i - last_oc + 1);
                last_oc = i+1;
            }
        }

        return res; 
    }
};