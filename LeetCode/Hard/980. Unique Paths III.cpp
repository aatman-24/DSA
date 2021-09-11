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

Question : 980. Unique Paths III
Topic : 2-D matrix Path
Problems : https://leetcode.com/problems/unique-paths-iii/
==============================> Explanation <=============================================


==============================> Edge Case <=============================================

1) Time = O(4 * 2^(M*N)) = O(2^(M*N))
   Space = O(M*N)(Aux) + O(M*N)(visited)

1) Time = O(4 * 2^(M*N)) = O(2^(M*N))
   Space = O(M*N)(Aux)
*/


class Solution {
public:

int xx[4] = {1, 0, 0, -1};
int yy[4] = {0, 1, -1, 0};

// check x and y is valid position to pass through.
bool isValid(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& visited) {

    if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1 || visited[x][y] == 1)
        return false;
    
    return true;
}


void solve(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& visited, int count, int &countPath) {

    // Reached target. Count == -1. (All Empty Block visited and next block is target block.)
    if(grid[x][y] == 2) {
        if(count == -1)
            countPath++;
        return;
    }

    // Extend to all the four direction.
    for(int i = 0; i < 4; i++) {

        int new_x = xx[i] + x;
        int new_y = yy[i] + y;

        // check this new pos is valid or not.
        if(isValid(new_x, new_y, grid, visited)) {

            // mark visited.
            visited[new_x][new_y] = 1;

            solve(new_x, new_y, grid, visited, count - 1, countPath);

            // backtrack.
            visited[new_x][new_y] = 0;
        }
    }
}

    int uniquePathsIII(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));

        int start_x, start_y;


        int count = 0, countPath = 0;
        for(int x = 0; x < m; x++) {
            for(int y = 0; y < n; y++) {
                if(grid[x][y] == 0) count++;
                if(grid[x][y] == 1) {
                    start_x = x, start_y = y;
                } 
            }
        }

        visited[start_x][start_y] = 1;
        solve(start_x, start_y, grid, visited, count, countPath);

        return countPath;
    }
};




// Without Extra Space(Eliminated Visited 2D Array)
.
class Solution {
public:

int xx[4] = {1, 0, 0, -1};
int yy[4] = {0, 1, -1, 0};

bool isValid(int x, int y, vector<vector<int>>& grid) {

    if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1 || grid[x][y] == -2)
        return false;
    
    return true;
}


void solve(int x, int y, vector<vector<int>>& grid, int count, int &countPath) {

    // Reached target. Count == -1. (All Empty Block visited and next block is target block.)
    if(grid[x][y] == 2) {
        if(count == -1)
            countPath++;
        return;
    }

    for(int i = 0; i < 4; i++) {

        int new_x = xx[i] + x;
        int new_y = yy[i] + y;

        if(isValid(new_x, new_y, grid)) {

            // Mark with -2. Means it is visited. But if it is not target then and only.
            if(grid[new_x][new_y] != 2) grid[new_x][new_y] = -2;

            solve(new_x, new_y, grid, count - 1, countPath);

            // Unmark with 0. (Backtrack)
            if(grid[new_x][new_y] != 2) grid[new_x][new_y] = 0;
        }
    }
}

    int uniquePathsIII(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        int start_x, start_y;


        int count = 0, countPath = 0;
        for(int x = 0; x < m; x++) {
            for(int y = 0; y < n; y++) {
                if(grid[x][y] == 0) count++;
                if(grid[x][y] == 1) {
                    start_x = x, start_y = y;
                } 
            }
        }

        grid[start_x][start_y] = -2;
        solve(start_x, start_y, grid, count, countPath);

        return countPath;
    }
};