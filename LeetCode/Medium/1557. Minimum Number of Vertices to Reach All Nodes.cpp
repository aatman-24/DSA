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

Question: 1557. Minimum Number of Vertices to Reach All Nodes
Topic : Graph, Topo Sort
Problems : https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
==============================> Explanation <=============================================
Given that Graph is DAG.
Simple, indegree[i] == 0 means no node can reach to that node so it must be in answer. all other
node indegree[i] != 0 can be reach out by some other node.

==============================> Apporach and Time Complexity <=============================================


1) Kahns' Algorithm:
Time = O(E)
Space = O(N)

*/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

        vector<int> indegree(n, 0);

        for(auto e: edges) {
            indegree[e[1]]++;
        }

        vector<int> ans;

        for(int i = 0; i < n; i++)  {
            if(indegree[i] == 0)
                ans.push_back(i);
        }


        return ans;
    }
};