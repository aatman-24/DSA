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

Question: 1091. Shortest Path in Binary Matrix
Topic : DFS, BFS
Problems : https://leetcode.com/problems/shortest-path-in-binary-matrix/

==============================> Explanation <=============================================
- Path Finding With 8 Directions.
- Can be solved using DFS also.
- We don't explore already visited the cell so it's time complexity is less but
if don't do that then it become the exponential.

==============================> Apporach and Time Complexity <=============================================

1) BFS:
Time: O(N+E) -> N = m*n, E = 8*m*n -> O(9*m*n) -> O(m*n)
Space: O(m*n)(Aux + Queue)

*/

class Solution {
public:
    int xx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
    int yy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if(grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;

        queue<pair<int,int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int level = 1;
        while(!q.empty()) {
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                
                auto [x, y] = q.front(); q.pop();

                if(x == n-1 && y == n - 1)
                    return level;

                for(int j = 0; j < 8; j++) {
                    int x_ = x + xx[j];
                    int y_ = y + yy[j];
                    if(x_ < 0 || y_ < 0 || x_ >= n || y_ >= n || grid[x_][y_] == 1)
                        continue;
                    q.push({x_, y_});
                    grid[x_][y_] = 1;
                }
            }
            level++;
        }

        return -1;
    }
};