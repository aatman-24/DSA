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

Question: 959. Regions Cut By Slashes
Topic : Graph, Path Finding, DFS
Problems : https://leetcode.com/problems/regions-cut-by-slashes/

==============================> Explanation <=============================================
Explanatino: 
https://leetcode.com/problems/regions-cut-by-slashes/discuss/869021/C%2B%2B-3x3-Pixel(Grid)-and-Union-Find(Whiteboard-Explanation-with-images)

1) Using DFS with Path Finding:
- Direct DFS not work. Need to make the given of (n, n) -> (3*n, 3*n). Because performing DFS
there is not any space.

So why we don't choose (2*n, 2*n) ? 

- still space is less.

[ ][/][ ][/]
[/][ ][/][ ]
[ ][/][ ][ ]
[/][ ][ ][ ]
If we used a scale of size 2 here, the answer would be 5, when it should be 3. 

Why you may ask? It's because the diagonal in the middle cannot locate the diagonals 
next to it because we search only top, right, bottom, and left. Thus reinforcing 
the OPs answer saying that the lines are too thick to identify empty areas correctly.

However, if we would scale this to a factor of 3, we get:
[ ][ ][/][ ][ ][/]
[ ][/][ ][ ][/][ ]
[/][ ][ ][/][ ][ ]
[ ][ ][/][ ][ ][ ]
[ ][/][ ][ ][ ][ ]
[/][ ][ ][ ][ ][ ]


- Then Peform Simple DFS for finding total component of given matrix. 

But how to zoom the edge ?

Here is the equation you need to find.

edge == '/' -> (3*i, 3*j+2), (3*i+1, 3*j+1), (3*i+2, 3*j) 
edeg == '\' -> (3*i, 3*j), (3*i+1, 3*j+1), (3*i+2, 3*j+2)

set all are as 1 if edge is found at (i, j) in original matrix.

Same as 200. Number of Islands.





2) Union-Find:

- Intersting How the Graph is established from the matrix it another level.

We divide the each cell into the four part (top, left, right, down) -> (0, 1, 2, 3)

So if there are, n * n cell then it will become 4*n*n.

so we first create parent[4*n*n], which point to itself.



How the graph is connnected with edge ?

- Graph is connected is based on '/' or '\' or ' '. If you notice the Cell which is divded into 4 parts.

1) '/' -> In a cell:        union(base+0, base+1), union(base+2, base+3)
          Neighbor cell:    union(base+2, base+5) -> union(base+3, 4*n*row+4*(col+1) + 1) (with the next column)

2) '\' -> In a cell:        union(base+0,base+2), union(base+1,base+3)
          Neighbor cell:    union(base+3, 4*n*(row+1)+4*col) (with the next row)

3) ' ' -> Peform both 1 and 2.

base = 4 * n * row + 4 * col -> Which indicate start position of the cell in a form of 4.

And last count the total number of cell, parent[i] == i. Which is the answer.


==============================> Apporach and Time Complexity <=============================================

1) DFS with Extra Visited Array:
Time : O(N^2)
Space : O(N^2) + O(N^2)(Aux)

1) DFS:
Time: O(N^2)
Space: O(N^2)(Aux)

*/

class Solution {
public:
   
    int xx[4] = {1, 0, -1, 0};
    int yy[4] = {0, 1, 0, -1};

    bool isValid(int x, int y, vector<vector<int>> &arr) {
        if(x < 0 || y < 0 || x >= arr.size() || y >= arr[0].size() || arr[x][y] != 0)
            return false;
        return true;
    }

    void dfs(int x, int y, vector<vector<int>> &arr) {
        
        // mark as visited.
        arr[x][y] = 2;

        for(int i = 0; i < 4; i++) {
            
            int x_ = xx[i] + x;
            int y_ = yy[i] + y;

            if(isValid(x_, y_, arr)) {
                dfs(x_, y_, arr);
            }
        }
    }


    int regionsBySlashes(vector<string>& grid) {

        int n = grid.size();

        vector<vector<int>> arr(n*3, vector<int>(n*3, 0));

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid.size(); j++) {

                if(grid[i][j] == '/') {
                    arr[3*i][3*j+2] = arr[3*i+1][3*j+1] = arr[3*i+2][3*j] = 1;
                }
                else if(grid[i][j] == '\\') {
                    arr[3*i][3*j] = arr[3*i+1][3*j+1] = arr[3*i+2][3*j+2] = 1;
                }
            }
        }

        // count component.
        int comp = 0;
        for(int i = 0; i < n * 3; i++) {
            for(int j = 0; j < n * 3; j++) {

                if(arr[i][j] == 0) {
                    dfs(i, j, arr);
                    comp++;
                }
            }
        }

        return comp;
    }

};



class Solution {
public:

    int findParent(int u, vector<int> &parent) {
        if(parent[u] == u)
            return u;
        return parent[u] = findParent(parent[u], parent);
    }


    void union_(int u, int v, vector<int> &parent) {
        u = findParent(u, parent);
        v = findParent(v, parent);

        if(u != v) {
            parent[u] = v;
        }
    }

    int regionsBySlashes(vector<string>& grid) {

        int n = grid.size();

        // Create parent for Union-Find with size of 4*n*n.
        vector<int> parent(4*n*n, 0);

        // make it own parent.
        for(int i = 0; i < 4*n*n; i++)
            parent[i] = i;


        for(int row = 0; row < n; row++) {
            
            for(int col = 0; col < n; col++) {

                // calculate base.
                int base = 4*n*row + 4*col;

                // for the '\' nad ' '.
                if(grid[row][col] != '/') {
                    union_(base, base+2, parent);
                    union_(base+1, base+3, parent);
                }
                // neighbor cell connection. (with the next row).
                if(row < n - 1) {
                    union_(base+3, 4*n*(row+1)+4*col, parent);
                }


                // for the '/' and ' '
                if(grid[row][col] != '\\') {
                    union_(base, base+1, parent);
                    union_(base+2, base+3, parent);
                }
                // neighbor cell connection. (with the next column).
                if(col < n - 1) {
                    union_(base+2, 4*n*(row)+4*(col+1) + 1, parent);
                }
            }
        }

        // count the answer.
        int ans = 0;
        for(int i = 0; i < 4*n*n; i++) {
            if(parent[i] == i)
                ans++;
        }

        return ans;
    }
};