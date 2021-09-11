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

Question: 1631. Path With Minimum Effort
Topic : DFS, Binary Search, Dijkstra in 2D matrix.
Problems : https://leetcode.com/problems/path-with-minimum-effort/

==============================> Explanation <=============================================
1) In dijkstra algorithm, we choose the best route which give the shortest distance. But 
distance is calculated based on problem.

    if(u, v) -> is fixed and dist is found for dist[u][v].

    the all the neighbors(u', v')

    dist[u'][v'] = max(dist[u][v], (abs(mat[u][v] - mat[u'][v']))) 

- Either (u, v) parent dist or the edge weight if it is maximum. 

We choose the maximum distance possible for all the neighbors and choose which is minimum.
    dist[u][v] = min(dist[u][v], max(dist[u'][v'], abs(dist[u][v] - dist[u'][v']))) (for simplacity)

- But using Dijkstra algorithm we always choose the minimum distance node to extend first. So 
need to check only max condition. 

2) Binary Search: we use distThreshold from (0, 10^6) and every time we see it is any path from
(0, 0) -> (m-1, n-1) can reach or not. If decrease the high otherwise we increase the low. Reachable or not
it is checked through the DFS.


==============================> Apporach and Time Complexity <=============================================

1) Dijkstra:
Time: O(ElogV) -> E = 4 * M * N , V = M*N. -> O(4*M*N * log(M*N))
Space: O(N^2)(Aux)

2) DFS + Binary Search:
Time : O(log(K) * m * n) -> K = 10^6.
Space: O(N^2)

*/



class Solution {
public:
        
    int xx[4] = {1, 0, -1, 0};
    int yy[4] = {0, 1, 0, -1};
        
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size(), n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0,0,0});

        while(!pq.empty()) {

            auto it = pq.top(); pq.pop();
            
            int d = it[0], u = it[1], v = it[2];

            if(dist[u][v] < d)
                continue;

            if(u == m - 1 && v == n - 1)
                return d;

            for(int i = 0; i < 4; i++) {

                int x_ = u + xx[i];
                int y_ = v + yy[i];

                if(x_ < 0 || y_ < 0 || x_ >= heights.size() || y_ >= heights[0].size())
                    continue;

                int newDist = max(d, abs(heights[u][v] - heights[x_][y_]));
                

                // Only If the dist[x_][y_] is updated then and only we push into pq.
                if(newDist < dist[x_][y_]) {
                    dist[x_][y_] = newDist;
                    pq.push({newDist, x_, y_});
                }
            }

        }


        return 0;
    }


};



class Solution {
public:
    
    int xx[4] = {1, 0, -1, 0};
    int yy[4] = {0, 1, 0, -1};
        

    bool dfs(int x, int y, vector<vector<int>> &visited, vector<vector<int>> &mat, int thershold) {

        if (x == mat.size() - 1 && y == mat[0].size() - 1) {
            return true;
        }

        visited[x][y] = 1;

        for(int i = 0; i < 4; i++) {

            int x_ = x + xx[i];
            int y_ = y + yy[i];

            if(x_ < 0 || y_ < 0 || x_ >= mat.size() || y_ >= mat[0].size() || visited[x_][y_])
                continue;

            // check if current (x, y) -> (x_, y_) is less than thershold and (x_, y_) -> (m-1, n-1)
            // reached using given threshold.
            if(abs(mat[x][y] - mat[x_][y_]) <= thershold && dfs(x_, y_, visited, mat, thershold))
                return true;
        }

        return false;
    }


    bool canReachDestination(vector<vector<int>>& mat, int thershold) {
       
        int m = mat.size(), n = mat[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        return dfs(0, 0, visited, mat, thershold);
    }

    int minimumEffortPath(vector<vector<int>>& heights) {

        int left = 0, right = 1000000, ans = 1000000;

        // Binary Search (0, 10^6).
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(canReachDestination(heights, mid)) {
                right = mid - 1;
                ans = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;

    }

};

int parent[1001];

int findParent(int u) {
    if(parent[u] == u)
        return u;
    return parent[u] = findParent(parent[u]);
}

void union_(int u, int v) {
    u = findParent(u);
    v = findParent(v);
    if(u != v) {
        parent[v] = u;
    }
}

int getDistance(int i, int j, vector<vector<int>> &points) {
    return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
}

int minCostConnectPoints(vector<vector<int>>& points) {

    int n = points.size();

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    for(int i = 0; i < points.size(); i++) {
        for(int j = i + 1; j < points.size(); j++) {
            pq.push(getDistance(i, j, points), i, j);
        }
    }

    int V = 0, mst = 0;

    while(V != n - 1) {

        auto it = pq.top(); pq.pop();
        int d = it[0], u = it[1], v = it[2];

        int parentOfU = findParent(u);
        int parentOfV = findParent(v);

        if(parentOfU != parentOfV) {
            union_(u, v);
            mst += d;
            V++;
        }
    }

    return mst;
}