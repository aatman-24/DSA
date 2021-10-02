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

Question: 1625. Lexicographically Smallest String After Applying Operations
Topic : Brute Force
Problems : https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/
==============================> Explanation <=============================================
Brute Force By DFS same we can do using BFS...


==============================> Apporach and Time Complexity <=============================================
1) BruteForce:
Time: 
Space: 
*/


class Solution {
public:

    unordered_map<string, int> visited;
    string answer;


    string rotate(string s, int by) {
       reverse(s.begin(), s.end());
       reverse(s.begin(), s.begin() + by);
       reverse(s.begin() + by, s.end());
       return s;
    }

    string add(string s, int a) {

       for(int i = 1; i < s.size(); i+=2) {
          char& c = s[i];
          c = '0' + (c - '0' + a) % 10;
       }
       return s;
    }


    void dfs(string s, int &a, int &b) {

       if(visited.count(s))
          return;

       if(s < answer)
          answer = s;

       visited[s] = 1;
       dfs(rotate(s, b), a, b);
       dfs(add(s, a), a, b);
    }



    string findLexSmallestString(string s, int a, int b) {

       answer = s;

       dfs(s, a, b);
       return answer;
    }
};