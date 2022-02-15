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
d
/*
==============================> Description <=============================================

Question :  96. Unique Binary Search Trees
Topic : Tree, Catalan Number
Problems : https://leetcode.com/problems/unique-binary-search-trees/

==============================> Explanation <=============================================

Actual Tree is found in this program.

- Leetcode: 95. Unique Binary Search Trees II

https://github.com/aatman-24/DSA/blob/main/LeetCode/Medium/95.%20Unique%20Binary%20Search%20Trees%20II.cpp

Count is application of Number therory(Catalan number: )
    
Formula:  C(N) = Sum(0->N-1)[C(i) * C(n-i-1)] N >= 1.


==============================> Edge Case <=============================================

*/


class Solution {

public:
    
    const int MAX_SIZE = 21;
        
    vector<ll> catalan;

    void initialize_the_catlan_seires() {

        catalan[0] = catalan[1] = 1LL;
        
        for (int i = 2; i < MAX_SIZE; i++) {
            
            catalan[i] = 0LL;
            
            for (int j = 0; j < i; j++)
                
                catalan[i] += catalan[j] * catalan[i - j - 1];
        }

    }

    // Find the nth catalan number using DP.
    int numTrees(int n) {
        
        if(catalan.size() == 0) {
            catalan.assign(MAX_SIZE, 1LL);
            initialize_the_catlan_seires(); 
        }
    
        return catalan[n];
    }


    // Same Check Catalan number therory.
    public int numTrees(int n) {
      int [] G = new int[n+1];
      G[0] = G[1] = 1;
        
      for(int i=2; i<=n; ++i) {
        for(int j=1; j<=i; ++j) {
          G[i] += G[j-1] * G[i-j];
        }
      }
      return G[n];
    }
};