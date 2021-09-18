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

Question: 1992. Find All Groups of Farmland
Topic : DFS, BFS
Problems : https://leetcode.com/problems/find-all-groups-of-farmland/

==============================> Explanation <=============================================
- farmland is rectangle the main things. It means that if the any edge is increased
the total rectangle must be increase.

- So using DFS is very simple(not proper DFS) only expand the edge unless condition
hold.

- Why BFS?

1 2 3 4
5 6 7 8
9 a b c

-> Then last added into the queue is C which gurantees by using 4 directional BFS.
So No need to keep track of any edge hold the condition or not.

==============================> Apporach and Time Complexity <=============================================

1) BFS:
Time: O(M*N)
Space: O(M*N)(Queue)

2) DFS:
Time: O(M*N)
Space: O(1)

*/


class Solution {
public:
    int xx[4] = {1, 0, -1, 0};
    int yy[4] = {0, 1, 0, -1};

    vector<vector<int>> ans;

    void bfs(int startX, int startY, vector<vector<int>> &grid) {

        queue<pair<int,int>> q;
        q.push({startX, startY});
        grid[startX][startY] = 0;

        int lastX = -1, lastY = - 1; 

        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto [x, y] = q.front(); q.pop();
                lastX = x, lastY = y;
                for(int j = 0; j < 4; j++) {
                    int x_ = x + xx[j];
                    int y_ = y + yy[j];
                    if(x_ < 0 || y_ < 0 || x_ >= grid.size() || y_ >= grid[0].size() || grid[x_][y_] == 0)
                        continue;
                    q.push({x_, y_});
                    grid[x_][y_] = 0;
                }
            }
        }

        ans.push_back({startX, startY, lastX, lastY});

    }


    vector<vector<int>> findFarmland(vector<vector<int>>& land) {

        int m = land.size(), n = land[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(land[i][j] == 1) {
                    bfs(i, j, land);
                }
            }
        }

        return ans;
    }
};



class Solution {
public:

    vector<vector<int>> ans;

    void dfs(int startX, int startY, vector<vector<int>> &grid) {

        int m = grid.size(), n = grid[0].size();

        int lastX = startX;
        while(lastX < m && grid[lastX][startY]) {
            lastX++;
        }
        lastX = lastX == 0 ? lastX: lastX-1;

        int lastY = startY;
        while(lastY < n && grid[startX][lastY]) {
            lastY++;
        }
        lastY = lastY == 0 ? lastY: lastY-1;


        // mark all the rectangle as visited.
        for(int i = startX; i <= lastX; i++) {
            for(int j = startY; j <= lastY; j++) {
                grid[i][j] = 0;
            }
        }

        ans.push_back({startX, startY, lastX, lastY});
    }



    vector<vector<int>> findFarmland(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dfs(i, j, grid);
                }
            }
        }

        return ans;
    }
};