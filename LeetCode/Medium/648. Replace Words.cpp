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

Question: 648. Replace Words
Topic : Trie
Problems : https://leetcode.com/problems/replace-words/

==============================> Explanation <=============================================
1) Brute Force: Check every word is replaced by each root or not. Replaced with the smaller root.

2) Trie: Remaining..

==============================> Apporach and Time Complexity <=============================================
1) BruteForce:
Time: O(N*M*L) -> N = dict.size(), M = string_Words.size(), L = Longest word size
Space: O(M)
*/


class Solution {
public:

   bool isMatched(string word, string root) {
      for(int i = 0, j = 0; i < root.size(); i++, j++) {
         if(word[i] != root[j])
            return false;
      }
      return true;
   }


   string replaceWords(vector<string>& dictionary, string sentence) {

      vector<string> ds;
      string word;
      stringstream ss(sentence);
      while(getline(ss, word, ' ')) {
         ds.push_back(word);
      }


      for(auto root: dictionary) {
         for(int i = 0; i < ds.size(); i++) {
            if(root.size() < ds[i].size() && isMatched(ds[i], root)) {
               ds[i] = root;
            }
         }
      }

      string ans = ds[0];
      for(int i = 1; i < ds.size() ; i++) {
        ans += ' ' + ds[i];
      }
      return ans;
   }
};