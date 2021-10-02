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

Question: 524. Longest Word in Dictionary through Deleting
Topic : String
Problems : https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/

==============================> Explanation <=============================================
1) Brute Force Method: Check every N word is subsequence or not of S. Choose longest and lexographically smaller one.
2) Sort the dictionary and do the same.

==============================> Apporach and Time Complexity <=============================================
1) Brute Force:
Time: O(N*M*L) -> N = s.size() and M = dictinoary.size() and L = longest Word in dictionary.
Space:  O(1)
*/


class Solution {
public:

    // check word is subsequence of s or not.
    bool isSubSequence(string s, string word) {

       int j = 0;
       for(int i = 0; i < s.size(); i++) {
          if(s[i] == word[j])
             j++;
       }
       return j == word.size();
    }



    string findLongestWord(string s, vector<string>& dictionary) {

       string ans = "";

       for(string word: dictionary) {

          // if current word size is greater or equal than we check weather word is subsequence or not.
          if(ans.size() <= word.size() && isSubSequence(s, word)) {
        
            // both size are same then current word needs to be lexogrphiaclly smaller.
            if(word.size() == ans.size()) {
                if(word < ans)
                    ans = word;
            }
        
            // if word.size() > ans.size();
            else {
                ans = word;
            }
          }
       }

       return ans;
    }
};