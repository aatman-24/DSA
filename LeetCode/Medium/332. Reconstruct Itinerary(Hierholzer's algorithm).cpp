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

Question :332. Reconstruct Itinerary(Hierholzer's algorithm)
Topic : Graph, DFS, Eulerain Path
Problems : https://leetcode.com/problems/reconstruct-itinerary/

==============================> Explanation <=============================================

- How to visit in lexical order ?

-> We first sort all the Edge. So when A -> C and A -> B is given A -> {B, C} order maintain.

-> We create the graph reprsentation as adjacencyList.
        <node, list[{node, visited}]>


==============================> Apporach and Time Complexity <=============================================

1) DFS + Eulerain Path + Edge Sorting:
Time = O(E*logE)(Sort Edges) + O(N+E)(DFS)
Space = O(N)(Aux) + O(N)(Stack)

*/

class Solution {
public:

    void dfs(unordered_map<string, vector<pair<string, int>>> &graph, stack<string> &st) {

        // pop out the currently added node.
        string current_station = st.top(); st.pop();

        // visit all it's neighbors which is not visited.
        for(auto &neighbors: graph[current_station]) {

            if(neighbors.second == 0) {
                neighbors.second = 1;
                
                // add into the stack.
                st.push(neighbors.first);
                dfs(graph, st);
            }
        }

        // all the neighbors is added to the stack first after that current node is added.
        st.push(current_station);
    }

    static bool sort_func(vector<string> &a, vector<string> &b) {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }


    vector<string> findItinerary(vector<vector<string>>& tickets) {

        int n = tickets.size();

        unordered_map<string, vector<pair<string, int>>> graph;

        sort(tickets.begin(), tickets.end(), sort_func);

        for(int i = 0; i < n; i++) {
            graph[tickets[i][0]].push_back({tickets[i][1], 0});
        }

        stack<string> st;
        st.push("JFK");

        dfs(graph, st);
        

        vector<string> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        

        return ans;
    }

};