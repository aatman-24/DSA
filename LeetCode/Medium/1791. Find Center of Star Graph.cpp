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

Question: 1791. Find Center of Star Graph
Topic : Graph, Indegree, Outdegree
Problems : https://leetcode.com/problems/find-center-of-star-graph/
==============================> Explanation <=============================================
- Easy
The Node which is repeated in edge. It is the center because it is given that
Graph is MST so we don't found extra edge so in result don't found other node
extra in edge.
==============================> Apporach and Time Complexity <=============================================

 O(1) (Because early stop)
 
1) Indegree + Extra Space:
Time: O(1) (Because early stop)
Space: O(100000)

2) Indegree + Set:
Time: O(1)
Space: O(1)

3) 
Time:O(1)
Space:O(1)

*/


class Solution {
public:
    
    vector<int> count;

    int findCenter(vector<vector<int>>& edges) {

        count.assign(100000, 0);
        
        for(auto edge: edges) {
            if(count[edge[0]] > 0)
                return edge[0];
            count[edge[0]]++;

            if(count[edge[1]] > 0)
               return edge[1];
            count[edge[1]]++; 
        }

        return 0;
    }
};

class Solution {

public:

    int findCenter(vector<vector<int>>& edges) {

        unordered_set<int> st;
        for(auto edge: edges) {
            if(st.count(edge[0]))
                return edge[0];
            st.insert(edge[0]);

            if(st.count(edge[1]))
                return edge[1];
            st.insert(edge[1]);
        }

        return 0;
    }

};


int findCenter(vector<vector<int>>& e) {
    return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
}