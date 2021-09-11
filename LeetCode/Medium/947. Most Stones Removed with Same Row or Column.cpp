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

Question: 947. Most Stones Removed with Same Row or Column
Topic : Graph, DFS, Union Find
Problems : https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

==============================> Explanation <=============================================
ID means index of the Given Stone array. It is very useful to create the graph. Rathar than 
soving this problem in terms of matrix it is graph problem. 

1) DFS Solution + ID:
- Here We start with 0 Id(idx) and go upto N. If the given point is not visited create a component
which starting point become that point. Now find all the points(idx of given array) which
match with that node (x, y). Means any point(idx is not visited) and (x == x1 || y == y1) then 
which that (x1, y1) point(which that idx into the array). 

- In short all points (xi, yi) which match (x, y) must be visited into single DFS Cycle.

- When in main method if the point is not visited already means it create a new component. So we
perform comp++. 

- At last answer is = N(number of point) - created componet = Removed point.




2) Union Find + ID:

- For UF we create only parent array not needed rank array here.

1) First all points is own parent.

2) Now we take every point combinatation, If point1(idx-1) is match with point2(idx-2) then,
    we take union(x, y). All things is same with Union Find templates.

3) At last count how many point has parent is itself which become = total component.

Answer = N - total Component


3) Union Find(Standard) + Trick:

- In solution we take the combination of every point and if it match we take the union. That's 
costly.

- This problem is occur due to row and column can be single number. (1, 0) -> (3, 1)
both row-1 and col-1 we can not separate there so direct union find is not possbile. 

- Here, we try to do that.

1) Given that (x, y) x & y <= 10000.

    So you can change y' = 10000 + y.

2) (x, y) = (x, ~y). (used here). if y = 8. 0000 0000 0000 1000 -> y' = 1111 1111 1111 0111 >= 10000.
    So it is worked here.

3) Standard way to use is, convert into the string so when we use map no problem occur.
    
After doing this we can not use parent[]. So for that reason used unorderd_map. Other all things 
is same.


==============================> Apporach and Time Complexity <=============================================


1) DFS Solution + ID:

Time = O(N^2) -> Reason is that all ID is visited only one time so overall it is O(N^2).
Space = O(N)(Visited) + O(N)(Aux)  

2) Union Find + ID:
Time = O(4K * N^2) -> UF = O(4K) * O(N^2)
Space = O(N)(Parent) + O(N)(Aux)

3) Union Find(Standard) + Trick:
Time = O(4K * N) -> UF = O(4K) * O(N)
Space = O(N)(ParentMap) + O(N)(Aux)

*/


class Solution {

public:

    void dfs(int node, vector<int> &visited, vector<vector<int>> &stones) {
        visited[node] = 1;


        // visit all the node which is (node, j) == (node, i) or (i, node) == (j, node). i and j anything.
        for(int i = 0; i < visited.size(); i++) {

            // check If it is not visited and any of x or y corrdinate is same then visit it.
            if(!visited[i] && (stones[i][0] == stones[node][0] || stones[i][1] == stones[node][1])) {
                dfs(i, visited, stones);
            }
        }
    }


    int removeStones(vector<vector<int>>&stones) {

        int N = stones.size();
        vector<int> visited(N, 0);
        int comp = 0;


        for(int i = 0; i < N; i++) {        // O(N) 

            if(!visited[i]) {
                dfs(i, visited, stones);    // O(N) This call is made for every ID only once
                                            // Either here or in dfs().
                // count compnent.
                comp++;
            }
        }                                      // = O(N^2)

        return N - comp;
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
        parent[u] = v;
    }

    int removeStones(vector<vector<int>>& stones) {

        int N = stones.size();

        vector<int> parent(N, 0);
        for(int i = 0; i < N; i++) parent[i] = i;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {

                // If any match then perform union of idex.
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    union_(i, j, parent);
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < N; i++) {
            if(i == parent[i]) {
                cnt++;
            }
        }

        return N - cnt;
    }

};




class Solution {

public:
    
    unordered_map<int,int> parent;
    int comp = 0;

    int findParent(int u) {

        // If element u does not have entry then make entry first. u -> u. Increase comp.
        if(parent.find(u) == parent.end()) {
            parent[u] = u;
            comp++;
        }

        if(parent[u] == u)
            return parent[u];

        return parent[u] = findParent(parent[u]);
    }

    void union_(int u, int v) {

        u = findParent(u);
        v = findParent(v);

        // If both are not same. Now make it in single component. So change parent of u -> v.
        // and decrease the comp by 1.
        if(u != v) {
            parent[u] = v;
            comp--;
        }    
    }

    int removeStones(vector<vector<int>>& stones) {

        for(int i = 0; i < stones.size(); i++) {
            union_(stones[i][0], ~stones[i][1]);
        }

        return stones.size() - comp;
    }

};