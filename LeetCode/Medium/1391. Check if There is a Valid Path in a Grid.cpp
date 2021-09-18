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

Question: 1391. Check if There is a Valid Path in a Grid
Topic : DFS, BFS
Problems : https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/submissions/

==============================> Explanation <=============================================
- Path Finding Problem.

Solved using, DFS, BFS and also Union-Find.

Graph Construction and how the path is derived is imp, other all thigns is same
as four direction path finding in matrix.

- If we go (i, j) -> (i', j') then we also check that (i', j') -> (i, j) is possible
or not then and only there is path.


==============================> Apporach and Time Complexity <=============================================

1) BFS:
Time: O(N+E) -> N = m*n, E = 4*m*n -> O(5*m*n) -> O(m*n)
Space: O(m*n)(Aux) + O(m*n)(Visited)


Why 4*M*N EDGE -> Because (i, j) -> (i', j') (2 possible checking)
                          (i', j') -> (i, j) (2 possible checking)

                          Overall 4 that' why I take E = 4*M*N. While it is only 2*M*N in graph manner.

*/

class Solution {
public:
    
unordered_map<int, vector<vector<int>>> dir;

    void make_dir() {
        dir[1] = {{0, -1}, {0, 1}};
        dir[2] = {{-1, 0}, {1, 0}};
        dir[3] = {{0, -1}, {1, 0}};
        dir[4] = {{0,  1}, {1, 0}};
        dir[5] = {{0, -1}, {-1, 0}};
        dir[6] = {{0, 1},  {-1, 0}};
    }
        
    // Checking that It is possible to go from curX, curY -> parentX, parentY in reverse manner
    // Then and only possible to go (parentX, parentY) -> (curX, curY).
    bool isValid(int curX, int curY, int parentX, int parentY, vector<vector<int>> &grid) {

        int num = grid[curX][curY];

        for(auto it: dir[num]) {
            
            if(curX + it[0] == parentX && curY + it[1] == parentY) {
                return true;
            }
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {

        make_dir();
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        queue<pair<int,int>> q;
        q.push({0, 0});
        visited[0][0] = 1;

        while(!q.empty()) {

            auto [x, y] = q.front(); q.pop();

            if(x == m - 1 && y == n - 1)
                return true;
            
            int num = grid[x][y];

            for(auto it: dir[num]) {

                int x_ = it[0] + x;
                int y_ = it[1] + y;

                if(x_ < 0 || y_ < 0 || x_ >= m || y_ >= n || visited[x_][y_] == 1)
                    continue;

                if(isValid(x_, y_, x, y, grid)) {
                    visited[x_][y_] = 1; 
                    q.push({x_, y_});
                }                
            }

        }

        return false;
    }

};