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

Question: 1765. Map of Highest Peak
Topic : BFS
Problems : https://leetcode.com/problems/map-of-highest-peak/

==============================> Explanation <=============================================
- Idea comes from picture,

Already Know that, water cell must be -> 0.
So it's Adjacent node are must be -> 1.
Again adjancen's adjacent should be -> 2.

Because we need maximized height so should use this greedy pattern. Which is
nothing but BFS traveral.

==============================> Apporach and Time Complexity <=============================================

1) BFS:
Time: O(M*N)
Space: O(M*N)(Queue)

*/


class Solution {
public:
   int xx[4] = {1, 0, -1, 0};
    int yy[4] = {0, 1, 0, -1};

    void addNeighbors(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &height, queue<pair<int,int>> &q) {

        for(int i = 0; i < 4; i++) {

            int x_ = x + xx[i];
            int y_ = y + yy[i];

            if(x_ < 0 || y_ < 0 || x_ >= grid.size() || y_ >= grid[0].size() || grid[x_][y_] || height[x_][y_])
                continue;

            q.push({x_, y_});
            height[x_][y_] = 1;
        }
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> height(m, vector<int>(n, 0));

        queue<pair<int,int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    addNeighbors(i, j, grid, height, q);
                }
            }
        }

        int level = 2;
        
        while(!q.empty()) {
            
            int size = q.size();
            
            for(int i = 0; i < size; i++) {

                auto [x, y] = q.front(); q.pop();

                 for(int j = 0; j < 4; j++) {

                    int x_ = x + xx[j];
                    int y_ = y + yy[j];

                    if(x_ < 0 || y_ < 0 || x_ >= grid.size() || y_ >= grid[0].size() || grid[x_][y_] || height[x_][y_])
                        continue;

                    q.push({x_, y_});
                    height[x_][y_] = level;
                }

            }
            level++;
        }

        return height;
    }
};