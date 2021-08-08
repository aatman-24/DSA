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

Question : 49. Group Anagrams
Topic : string, anagrams
Problems : https://leetcode.com/problems/group-anagrams/x/
/*
==============================> Explanation <=============================================
use unorderd_map<string, vector<string>> we sort the s and put the anagrams 
groups. and return all the group at last.

- here only lower case character is included that's why we can use counter sort
to make new string or sort the string rather than in-bulit for time complexity.

- use unordered_map rathar than map. no need of map(sorting).

*/



/*
==============================> Edge Case <=============================================


*/

class Solution {
public:

    static string strSort(string s) {

        int counter[26] = {0};
        for(char c : s) 
            counter[c - 'a']++;

        string t;
        for(int c = 0; c < 26; c++) 
            t += string(counter[c], c + 'a'); // t += (counter[c] times c+'a')

        return t;
    }   


    vector<vector<string>> groupAnagrams(vector<string> &arr)  {

        unordered_map<string, vector<string>> mp;
        
        for(string s: arr) {
            string tmp = strSort(s);
            if(mp.find(tmp) == mp.end()) {
                mp[tmp] = {s};
            }
            else {
                mp[tmp].push_back(s);
            }
        }

        vector<vector<string>> res;
        for(auto i : mp) {
            res.push_back(i.second);
        }

        return res;
    }

};