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

Question: 290. Word Pattern
Topic : String
Problems : https://leetcode.com/problems/word-pattern/

==============================> Explanation <=============================================
- Here we need to match the pattern character with word. Which is possible if we store that mapping somewhere
so next time we can match it again.

So we need map<char, string> to perform this.

Also once the character a -> "abc" then no character again match to the b -> "abc". For that we need to keep track
word is used only single time. 

For that purpose set<string> is used.


==============================> Apporach and Time Complexity <=============================================

1) Mapping
Time: O(N) ;N is length of pattern.
Space: O(N)

*/



class Solution {

public:

    bool wordPattern(string pattern, string s) {
        
        // Check substring(word) is already assigned to some char.
        set<string> used;

        // map pattern[i] with string(word).
        map<char, string> mp;

        int i = 0;
        string str;

        // generate the string stream.
        stringstream ss(s);

        // Split the stream with ' '.
        while(getline(ss, str, ' ')) {

            if(mp.count(pattern[i])) {
                if(mp[pattern[i]] != str)
                    return false;
            }
            else {
                
                if(used.count(str))
                    return false;

                mp[pattern[i]] = str;

                used.insert(str);
            }
            i++;
        }

        // finish the all pattern or not.
        return i == pattern.size();
    }
};