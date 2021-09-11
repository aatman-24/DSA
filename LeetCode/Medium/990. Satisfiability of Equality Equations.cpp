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

Question: 990. Satisfiability of Equality Equations
Topic : Graph, DFS, Union Find
Problems : https://leetcode.com/problems/satisfiability-of-equality-equations/
==============================> Explanation <=============================================
- Create the Graph on Equality and check The unEquality hold or not.


1) Union - Find: 

- First pass, Take union of all Equality node.

-  Validate Unequlity by checking both parent must be differnt if are same then it violate 
what is given.


2) DFS: Create graph based on Equality and then check for unequal node can not reach each other.


==============================> Apporach and Time Complexity <=============================================


1) Union - Find:

Time = O(N) 
Space = O(1) 

2) DFS:
Time = O(N)
Space = O(N)(Aux)


*/


class Solution {
public:
        
    int parent[26];

    int findParent(int u) {
        if(parent[u] == u)
            return u;
        return parent[u] = findParent(parent[u]);
    }

    void union_(int u, int v) {
        u = findParent(u);
        v = findParent(v);
        if(u != v) {
           parent[u] = v; 
        }
    }

    bool equationsPossible(vector<string>& equations) {

        for(int i = 0; i < 26; i++)
            parent[i] = i;

        for(string e: equations) {
            if(e[1] == '=') {
                union_(e[0]-'a', e[3]-'a');
            }
        }

        for(string e: equations) {
            if(e[1] == '!' && findParent(e[0]-'a') == findParent(e[3]-'a')) {
                return false;
            }
        }

        return true;
    }
};