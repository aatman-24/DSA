#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

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

Question : 1306. Jump Game III
Topic : DFS, BFS
Problems : https://leetcode.com/problems/jump-game-iii/
/*
==============================> Explanation <=============================================

45. Jump Game II -> Needs to find minimum number of jump to reach the last index.
55. Jump Game -> to check whether or we can reach at last index.


- This problem is not too much related with above problems.

Using DFS || BFS you can solve this problem. Here start pointing is given. And once you reach at
any point then again this points return false then taking it next time also it return false so all
the points visited once. 

so In first solution if you don't do this visited[i] = 0 then also works.


2] solution:

- All elements are going to visit only once so this concept are used here.

After visiting any elements we make it negative, 
    arr[i] = -arr[i].
And we check if arr[i] is negative then we don't go further and return false because we already visited
this element then it become negative. so again explore the same arr[i] don't make any sense.


And yes after making arr[i] = -arr[i] -> i + arr[i] becomes i - arr[i] and i - arr[i] becomes i + arr[i] so this is
trick to not use extra space.

*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:

    bool dfs(int i, vector<int>& arr, vector<int> &visited) {

        if(arr[i] == 0) return true;

        if(i + arr[i] < arr.size() && !visited[i+arr[i]]) {
            visited[i+arr[i]] = 1;
            if(dfs(i+arr[i], arr, visited)) return true;
            // visited[i+arr[i]] = 0;
        }


        if(i - arr[i] >= 0 && !visited[i-arr[i]]) {
            visited[i-arr[i]] = 1;
            if(dfs(i-arr[i], arr, visited)) return true;
            // visited[i-arr[i]] = 0;
        }

        return false;
    }

    // O(N) + O(N) [DFS]
    bool canReach(vector<int>& arr, int start) {

        int n = arr.size();
        vector<int> visited(n, 0);
        visited[start] = 1;
        return dfs(start, arr, visited);
    }



    // O(N) - O(1) [Recursive + Trick to check visited or not]
    bool canReach(vector<int>& arr, int i) {

        // only if we visit arr[i] first time then we explore it otherwise not.
        if(i >= 0 && i < arr.size() && arr[i] >= 0) {

            if(arr[i] == 0) return true;

            // make it negative so we don't again explore it.
            arr[i] = -arr[i];

            if(canReach(arr, i + arr[i])) return true;

            if(canReach(arr, i - arr[i])) return true;
        }

        return false;
    }

};