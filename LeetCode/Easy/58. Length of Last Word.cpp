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

Question: 58. Length of Last Word
Topic : String
Problems : https://leetcode.com/problems/length-of-last-word/

==============================> Explanation <=============================================

Keep track of last word length.

==============================> Apporach and Time Complexity <=============================================

1) String
Time: O(N)
Space: O(1)

*/



class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int n = s.size();
        int i = 0, ans = 0;

        while(i < n) {

            while(i < n && s[i] == ' ') i++;

            int last = 0;
            while(i < n && s[i] != ' ') {
                i++;
                last++;
            }

            ans = last > 0 ? last : ans;
        }

        return ans;
    }
};