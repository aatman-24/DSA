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

Question : 139. Word Break
Topic : DPOnString
Problems : https://leetcode.com/problems/word-break/

==============================> Explanation <=============================================

1) Backtracking:
- Try all the word... 


2) Top-Down:
- Use memorization to avoid duplicate function call.
t[i] -> indicate, [i, s.size()] is segemented or not. 


(i directly copied from other that is reason it is vice versa from top-down)
3) Bottom-up:
- dp[i] -> indicate [0, i] is segemented or not.

==============================> Apporach and Time Complexity <=============================================

1) Backtracking
Time: O(2^N)
Space: O(N)(Aux)


2) Top-Down + Bottom-up:
Time: O(N^2)
Space: O(N)

*/

// Backtracking -> O(2^N) + O(N)
class Solution {

public:

    bool solve(string s, int i, unordered_set<string> &st) {
        
        if(i == s.size())
            return true;


        for(int j = i; j < s.size(); j++) {

            string word = s.substr(i, j-i+1);
            
            if(st.count(word)) {

                if(solve(s, j+1, st)) {

                    return true;
                }
            }
        }

        return false;
    }



    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> st;
        for(string word: wordDict) {
            st.insert(word);
        }

        return solve(s, 0, st);
    }
};







// Memorization -> O(N^2) + O(N)

class Solution {

public:

    int t[301];

    bool solve(string s, int i, unordered_set<string> &st) {
        
        if(i == s.size())
            return true;

        if(t[i] != -1) {
            return t[i] == 1;
        }

        for(int j = i; j < s.size(); j++) {

            string word = s.substr(i, j-i+1);
            
            if(st.count(word)) {

                if(solve(s, j+1, st)) {

                    t[j+1] = 1;

                    return true;
                }
            }
        }


        t[i] = 0;

        return false;
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        

        memset(t, -1, sizeof(t));


        // t[i] -> indicate that, wheater [i, s.size()] can be segmented or not.

        unordered_set<string> st;
        for(string word: wordDict) {
            st.insert(word);
        }

        return solve(s, 0, st);
    }
};



// bottom-up DP.

class Solution {

public:

    bool wordBreak(string s, vector<string>& wordDict) {
        
        if(wordDict.size()==0) return false;

        unordered_set<string> dict;
        for(string word: wordDict) {
            dict.insert(word);
        }

        vector<bool> dp(s.size()+1,false);

        dp[0]=true;

        for(int i = 1; i <= s.size(); i++) {
            
            for(int j = i - 1; j >= 0; j--) {
                
                // dp[j] is true, means [0, j] is segmented.
                if(dp[j]) {

                    string word = s.substr(j, i-j);
                    
                    if(dict.count(word)) {

                        dp[i] = true;
                        break;

                    }

                }
            }
        }

        return dp[s.size()];

    }
};