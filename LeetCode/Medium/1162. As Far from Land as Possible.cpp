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

Question: 1162. As Far from Land as Possible
Topic : DFS, BFS
Problems : https://leetcode.com/problems/as-far-from-land-as-possible/

==============================> Explanation <=============================================
- DFS possible not suited (keep track of minimum distance). If you visit the cell(x, y)
and contain already minimum distance compare to current distance then no need to visit or expand again from that.
- DFS is tricky. Again don't solve BFS problem with DFS.

- Simple BFS we visit all the water node in level manner which give gurantee that
if water cell is visited then it is with minimum distance and no need to expand
again that cell in future.


==============================> Apporach and Time Complexity <=============================================

1) BFS:
Time: O(N+E) -> N = m*n, E = 4*m*n -> O(9*m*n) -> O(m*n)
Space: O(m*n)(Queue)

*/


class Solution {
public:

    int xx[4] = {1, 0, -1, 0};
    int yy[4] = {0, 1, 0, -1};

    int maxDistance(vector<vector<int>>& grid) {

        int n = grid.size();
    
        queue<pair<int,int>> q;

        // Adding all the land.
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    q.push({i, j});
                }
            }
        }

        // Base Case If all cell contain only land then we should return -1.
        if(q.size() == n*n )
            return -1;
        
        
        int level = 0;

        while(!q.empty()) {
            
            int size = q.size();

            for(int i = 0; i < size; i++) {

                auto [x, y] = q.front(); q.pop();

                for(int j = 0; j < 4; j++) {

                    int x_ = x + xx[j];
                    int y_ = y + yy[j];

                    if(x_ < 0 || y_ < 0 || x_ >= n || y_ >= n || grid[x_][y_] == 1)
                        continue;

                    q.push({x_, y_});

                    // We don't visit the same node again because using BFS
                    // we already know that if the cell are going to visited it means
                    // it is already have minimum distance.
                    grid[x_][y_] = 1;
                }

            }
            level++;
        }
        return level-1;
    }
};