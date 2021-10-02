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

Question: 784. Letter Case Permutation
Topic : Backtrack
Problems : https://leetcode.com/problems/letter-case-permutation/

==============================> Explanation <=============================================
Backtracking.....

If the character is lower case then change into the upper case and vice versa.(Same as 
either take it or don't take it).

==============================> Apporach and Time Complexity <=============================================
1) Backtracking:
Time:O(Branch^Depth) = O(N^N) -> Algorithm go upto N depth and N Branch in Worst Case.
Space:O(N)(Aux)
*/


class Solution {
public:

    bool isLowerCase(char ch) {
       return ch >= 'a' && ch <= 'z';
    }

    bool isUpperCase(char ch) {
       return ch >= 'A' && ch <= 'Z';
    }

    bool isNumber(char ch) {
       return ch >= '0' && ch <= '9';
    }

    vector<string> answer;

    void backtrack(string s, int idx) {
        
       // Put new String into the answer.
       answer.push_back(s);
        
       for(int i = idx; i < s.size(); i++) {
         
        // Number does not change the string.
          if(isNumber(s[i])) continue;
       
          if(isLowerCase(s[i])) {
             s[i] = s[i] - 32;
             backtrack(s, i+1);
             s[i] = s[i] + 32;
          }
          else if(isUpperCase(s[i])) {
             s[i] = s[i] + 32;
             backtrack(s, i+1);
             s[i] = s[i] - 32;
          }
       }
    }

    vector<string> letterCasePermutation(string s) {
       backtrack(s, 0);
       return answer;
    }
};