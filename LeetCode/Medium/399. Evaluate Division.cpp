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

Question: 399. Evaluate Division
Topic : Graph, DFS, BFS.
Problems : https://leetcode.com/problems/evaluate-division/
==============================> Explanation <=============================================
Used DFS.

if a -> b = 3 then b -> a = 1/3.

a/b and b/c given a/c = a/b * b/c = a -> b * b -> c.

This concept used with dfs.

==============================> Apporach and Time Complexity <=============================================

1) DFS:
Time = O(N^2)(DFS)
Space = O(N)(Aux)

2) BFS
Time = O()
*/



class Solution {
public:

    static bool isVisited(string node, unordered_map<string,string> visited) {

        if(visited.find(node) == visited.end()) {
            return false;
        }

        return true;
    }

    double dfs(string src, string target, unordered_map<string, vector<pair<string,double>>> &graph, unordered_map<string, string> &visited) {

        visited[src] = src;

        for(auto neighbors: graph[src]) {
            if(neighbors.first == target) {
                return neighbors.second;
            }
        }

        for(auto &neighbors: graph[src]) {

            if(!isVisited(neighbors.first, visited)) {

                if(neighbors.first == target) {
                    return neighbors.second;
                }

                double value = dfs(neighbors.first, target, graph, visited);

                graph[src].push_back({neighbors.first, value});
                graph[neighbors.first].push_back({src, 1/value});

                if(value != -1.0) {
                    return neighbors.second * value;
                }
            }
        }

        return -1.0;
    }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        unordered_map<string, vector<pair<string,double>>> graph;

        unordered_map<string, string> visited;
        
        for(int i = 0; i < equations.size(); i++) {
        
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], (1/values[i])});
        }

        int m = queries.size();
        vector<double> result(m);

        for(int i = 0; i < m; i++) {

            string src = queries[i][0], target = queries[i][1];

            if(graph.find(src) == graph.end() || graph.find(target) == graph.end()) {
                result[i] = -1;
            }
            else if(src == target) {
                result[i] = 1;
            }
            else {
                visited.clear();
                result[i] = dfs(src, target, graph, visited);
            }
        }

        return result;
    }
};

// DFS + MEMO
class Solution {
public:
    static bool isVisited(string node, unordered_map<string,string> visited) {

        if(visited.find(node) == visited.end()) {
            return false;
        }

        return true;
    }

    double dfs(string src, string target, unordered_map<string, vector<pair<string,double>>> &graph, unordered_map<string, string> &visited) {

        visited[src] = src;

        // check first if src -> target edge is there or not  if it is not then and only perform
        // dfs.
        for(auto neighbors: graph[src]) {
            if(neighbors.first == target) {
                return neighbors.second;
            }
        }

        for(auto &neighbors: graph[src]) {

            if(!isVisited(neighbors.first, visited)) {

                if(neighbors.first == target) {
                    return neighbors.second;
                }

                double value = dfs(neighbors.first, target, graph, visited);

                if(value != -1.0) {

                    // make edge from neighbor -> target (memorization).
                    graph[neighbors.first].push_back({target, value});
                    graph[target].push_back({neighbors.first, 1/ value});
                    
                    return neighbors.second * value;
                }
            }
        }

        return -1.0;
    }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        unordered_map<string, vector<pair<string,double>>> graph;

        unordered_map<string, string> visited;
        
        for(int i = 0; i < equations.size(); i++) {
        
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], (1/values[i])});
        }

        int m = queries.size();
        vector<double> result(m);

        for(int i = 0; i < m; i++) {

            string src = queries[i][0], target = queries[i][1];

            if(graph.find(src) == graph.end() || graph.find(target) == graph.end()) {
                result[i] = -1;
            }
            else if(src == target) {
                result[i] = 1;
            }
            else {
                visited.clear();
                result[i] = dfs(src, target, graph, visited);
            }
        }

        return result;
    }
};



// BFS.
class Solution {
public:
    static bool isVisited(string node, unordered_map<string,string> visited) {

        if(visited.find(node) == visited.end()) {
            return false;
        }

        return true;
    }

        double bfs(string src, string target, unordered_map<string, vector<pair<string,double>>> &graph, unordered_map<string, string> &visited) {

            queue<pair<string,double>> q;
            q.push({src, 1.0});
            visited[src] = src;

            while(!q.empty()) {

                auto node = q.front(); q.pop();

                if(node.first == target)
                    return node.second;

                for(auto neighbors: graph[node.first]) {
                    
                    if(!isVisited(neighbors.first, visited)) {
                        visited[neighbors.first] = neighbors.first;
                        q.push({neighbors.first, node.second * neighbors.second});
                    }
                }
            }

            return -1.0;
        }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        unordered_map<string, vector<pair<string,double>>> graph;

        unordered_map<string, string> visited;
        
        for(int i = 0; i < equations.size(); i++) {
        
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], (1/values[i])});
        }

        int m = queries.size();
        vector<double> result(m);

        for(int i = 0; i < m; i++) {

            string src = queries[i][0], target = queries[i][1];

            if(graph.find(src) == graph.end() || graph.find(target) == graph.end()) {
                result[i] = -1;
            }
            else if(src == target) {
                result[i] = 1;
            }
            else {
                visited.clear();
                result[i] = bfs(src, target, graph, visited);
            }
        }

        return result;
    }
};