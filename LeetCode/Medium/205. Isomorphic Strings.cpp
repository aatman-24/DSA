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

Question: 205. Isomorphic Strings
Topic : Map, String
Problems : https://leetcode.com/problems/isomorphic-strings/

==============================> Explanation <=============================================

- No Two different character should match the same characters. So used Map + Set/Map.

==============================> Apporach and Time Complexity <=============================================

1) String, Map
Time: O(N)
Space: O(1)

*/




class Solution {

public:

    bool isIsomorphic(string s, string t) {
        

        // Forward mapping
        unordered_map<char,char> mp;

        // Also set can be used.
        unordered_map<char,char> rv_mp;

        for(int i = 0; i < s.size(); i++) {

            if(mp.count(s[i])) {

                // If s[i] has matching character then all the occurance of s[i] match to the
                // same characters.
                if(mp[s[i]] != t[i])
                    return false;
            }
            else {
                // Not two character can match the same character.
                if(rv_mp.count(t[i]))
                    return false;
    
                mp[s[i]] = t[i];
                rv_mp[t[i]] = s[i];
            }
        }

        return true;
    }
};



class Solution {

public:

    bool isIsomorphic(string s, string t) {
        

        // Forward mapping
        unordered_map<char,char> mp;

        // Also set can be used.
        set<char> st;

        for(int i = 0; i < s.size(); i++) {

            if(mp.count(s[i])) {

                // If s[i] has matching character then all the occurance of s[i] match to the
                // same characters.
                if(mp[s[i]] != t[i])
                    return false;
            }
            else {
                // Not two character can match the same character.
                if(st.count(t[i]))
                    return false;
    
                mp[s[i]] = t[i];
                st.insert(t[i]);
            }
        }

        return true;
    }
};