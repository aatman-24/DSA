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

Question : 79. Word Search
Topic : DFS
Problems : https://leetcode.com/problems/word-search/

==============================> Explanation <=============================================
- We start from each(i, j)... if kth character is match with (i, j) cell we increase the seach by for matching (k+1) with
all four directions...

- We don't visit the same cell again for single DFS call so we mark each visited cell... and in backtrack we make it again unvisited.

- Any time if we reach the end of matching string.. means we found the string so we return true.

==============================> Apporach and Time Complexity <=============================================

1) DFS
Time: O(N^2)
Space: O(1)

*/
class Solution {

    const int xDim[4] = {1, 0, -1, 0};
    const int yDim[4] = {0, 1, 0, -1};

public:
        
    bool isFound(vector<vector<char>>& board, vector<vector<int>>& mark, string &word, int x, int y, int k) {
        
        if(k == word.size()) return true;

        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || word[k] != board[x][y] || mark[x][y] == 1)
            return false;

        mark[x][y] = 1;
        for(int i = 0; i < 4; i++) {

            int xx = x + xDim[i];
            int yy = y + yDim[i];

            bool fo = isFound(board, mark, word, xx, yy, k+1);
            if(fo) {
                return true;
            }           
        }
        mark[x][y] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size(), m = board[0].size();

        vector<vector<int>> mark(n, vector<int>(m, 0));
       
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isFound(board, mark, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};