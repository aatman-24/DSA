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

Question: 329. Longest Increasing Path in a Matrix
Topic : DFS, Island, BFS, TopoSort, DP
Problems : https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

==============================> Explanation <=============================================
- Can be solved using DP, BFS, TopoSort please check out.




==============================> Apporach and Time Complexity <=============================================

1) DFS + MEMO:
Time: O(M*N)
Space: O(M*N)(pacific) + O(M*N)(atlantic) + O(M*N)(Aux)

*/

class Solution {
public:

    int xx[4] = {1, 0, -1, 0};
    int yy[4] = {0, 1, 0, -1};


    int dfs(int x, int y, vector<vector<int>> &dist, vector<vector<int>> &grid) {

        // Keep track of longest path.
        int cur_dist = 0;

        // Try out all the four path if it is valid.
        for(int i = 0; i < 4; i++) {

            int x_ = x + xx[i];
            int y_ = y + yy[i];

            if(x_ < 0 || y_ < 0 || x_ >= grid.size() || y_ >= grid[0].size())
                continue;
            
            // check that nearest neighbors have more distance.
            if(grid[x_][y_] > grid[x][y]) {

                if(dist[x_][y_] == 0) {
                    dist[x_][y_] = dfs(x_, y_, dist, grid);
                }

                cur_dist = max(cur_dist, dist[x_][y_]);
            }           
        }

        // use memo.
        dist[x][y] = cur_dist + 1;

        return dist[x][y];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> dist(m, vector<int>(n, 0));

        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                // for every point which is not visited for that keep track of longest path.
                // because if it is already visited that mean it is cover in some other path which
                // can be maximum.
                if(dist[i][j] == 0) {
                    ans = max(ans, dfs(i, j, dist, matrix));
                }
            }
        }

        return ans;
    }
};