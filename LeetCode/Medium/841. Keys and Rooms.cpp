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

Question: 841. Keys and Rooms
Topic : Graph, DFS, BFS
Problems : https://leetcode.com/problems/keys-and-rooms/
==============================> Explanation <=============================================

Idea is that,

Check Given graph is single components or not.

==============================> Apporach and Time Complexity <=============================================

1) Find Single Component Using DFS:

Time = O(N+E)
Space = O(N)(Visited) + O(N)(Aux)
           
2) Find Single Component Using BFS:

Time: O(N + E)
Space: O(N)(Visited) + O(N)(Queue)

*/

class Solution {
public:
    void dfs(int src, vector<int> &visited, vector<vector<int>> &adjList) {
        visited[src] = 1;
        for(auto it:adjList[src]) {
            if(!visited[it]) {
                dfs(it, visited, adjList);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(), 0);
        visited[0] = 1;
        dfs(0, visited, rooms);
        for(int i = 0; i < rooms.size(); i++) {
            if(visited[i] == 0)
                return false;
        }
        return true;
    }
};


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(), 0);
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int node = q.front(); q.pop();
            visited[node] = 1;
            for(auto it: rooms[node]) {
                if(!visited[it]) {
                    q.push(it);
                }
            }
        }
        for(int i = 0; i < rooms.size(); i++) {
            if(visited[i] == 0)
                return false;
        }
        return true;
    }
};