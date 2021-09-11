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

Question: 1042. Flower Planting With No Adjacent
Topic : Graph, DFS, Greedy
Problems : https://leetcode.com/problems/flower-planting-with-no-adjacent/

==============================> Explanation <=============================================
- DFS with Backtraking is right soultion but it will give TLE for sure.

Idea is that,

- If any node has not more than 3 edge so it will gurantee that we can mark such graph using 4 color
so that conflict not occur.
- for that simple greedy algorithm works.

Algorithm:
- For every node,
    keep track of its adjacent node color and assign the color which is not already taken by the
    its adjacent node.

==============================> Apporach and Time Complexity <=============================================

1) DFS:
Time : O(4^(N+E))
Space : O(N+E)(adjList) + O(N)(Aux)


2) Greedy:
Time: O(N+E)
Space: O(N+E)
*/

// DFS TLE.
class Solution {
public:
    bool isValid(int node, int color, vector<int> color_arr, vector<int> adjList[]) {

        for(auto it: adjList[node]) {
            if(color_arr[it] != -1 && color_arr[it] == color)
                return false;
        }
        return true;
    }

    bool dfs(int src, vector<int> &color, vector<int> adjList[]) {

        for(auto it: adjList[src]) {

            if(color[it] == -1) {

                for(int i = 1; i <= 4; i++) {

                    if(isValid(it, i, color, adjList)) {

                        color[it] = i;
                        if(!dfs(it, color, adjList))
                            return false;
                    }
                }
            }
            else if(color[it] == color[src]) {
                return false;
            }

        }

        return true;
    }

    bool helper(int n, vector<int> &color ,vector<int> adjList[]) {

        for(int src = 1; src <= n; src++) {
            if(color[src] == -1) {
                for(int i = 1; i <= 4; i++) {
                    color[src] = i;
                    if(dfs(src, color, adjList))
                        break;
                }
            }
        }

        return false;
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

        vector<int> adjList[n+1];
        for(auto edge: paths) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n+1, -1);

        helper(n, color, adjList);
        return vector<int> (color.begin() + 1, color.end());
    }
};



class Solution {
public:

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

        vector<int> adjList[n];
        for(auto edge: paths) {
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }

        vector<int> ans(n, -1);

        // For every node.
        for(int i = 1; i <= n; i++) {


            // color from 1 to 4 is mark 1 if it is used otherwise 0.
            int used[5] = {0};

            // mark all the adjacent color in used array.
            for(auto it: adjList[i-1]) {
                if(ans[it] != -1)
                    used[ans[it]] = 1;
            }

            // choose any color which is not selected by its neighbor.
            for(int col = 1; col <= 4; col++) {
                if(used[col] != 1)
                    ans[i-1] = col;
            }

        }

        return ans;
    }



};