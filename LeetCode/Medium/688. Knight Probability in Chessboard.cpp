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

Question:  688. Knight Probability in Chessboard
Topic :Top-Down Bottom-up Pattern= MultiDimesional DP
Problems : https://leetcode.com/problems/knight-probability-in-chessboard/

==============================> Explanation <=============================================
Similar = 576. Out of Boundary Paths

- Dp variant = MultiDimesional DP.

1) Choise Diagram: At different moves(k) there are different possbility the knight jump to the 
                   out of bounds. So we need to take that into consideration.

                   when, k = 0 (knight is at (x, y)) position, 

                   so at next step k = 1, it must be jump from the previous position (x, y)

                   we need to check where the knight at last move(k-1) based on that 

                   calculation is made.
                
                - Here, we check all 8 possible position knight could jump, and if it is in
                matrix then we add those probablities while counting for current (x, y)

                - And at last we divide it total number of ways which is 8.

2) Base Case: K = 0(move = 0) and knight is on the board then it is prob is 1. Out of board
              in any case prob is 0.
              
3) Recurrance Relation:
    
        dp[moves][i][j] = dp[moves-1][xx][yy] -> xx and yy is all direction from (i, j).

- Space optimization is possible because we just using the previous level(moves) information.

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern=Target Sum, Coin Change
Time: O(N^3)
Space: O(N^3)

2) Bottom-up Pattern= Target Sum, Coin Change
Time: O(N^3)
Space: O(N^2)

*/


class Solution {
public:

    vector<vector<int>> directions = {{1,2},{1, -2}, {2, 1}, {2, -1},{-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
        
    double t[101][26][26];

    double knightProbabilitySolve(int i, int j, int k, int n) {
            
        // Out of Bounds return prob 0.
        if(i < 0 || j < 0 || i >= n || j >= n)
            return 0;
        
        // When k = 0, and (i, j) in the matrix then prob is 1.
        if(k == 0)
            return 1;
        
        if(t[k][i][j] != -1)
            return t[k][i][j];
        

        double totalProb = 0;
        for(auto dir : directions) {
            
            int xx = dir[0] + i;
            int yy = dir[1] + j;
            
            // prob of (OR) is added together.    
            totalProb += knightProbabilitySolve(xx, yy, k-1, n);
        }
        
        // there are 8 possible direction so divide by that.
        return t[k][i][j] = (double)totalProb/8;
    }


    double knightProbability(int n, int k, int row, int column) {


        // memset for double value does not work for that reason.
        for(int i = 0; i <= k; i++) {
            for(int j = 0; j <= n; j++) {
                for(int l = 0; l <= n; l++) {
                    t[i][j][l] = -1;
                }
            }
        }
        
        return knightProbabilitySolve(row, column, k, n);
    }


};



class Solution {
public:

    vector<vector<int>> directions = {{1,2},{1, -2}, {2, 1}, {2, -1},{-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};

    double knightProbability(int n, int moves, int row, int column) {

        vector<vector<vector<double>>> dp(moves+1, vector<vector<double>>(n+1, vector<double>(n+1, 0)));
        
        // base case, k = 0 all position have prob 1.
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dp[0][i][j] = 1;
            }
        }

        for(int k = 1; k <= moves; k++) {

            for(int i = 0; i < n; i++) {

                for(int j = 0; j < n; j++) {

                    double totalProb = 0;

                    for(auto dir : directions) {
                        
                        int xx = dir[0] + i;
                        int yy = dir[1] + j;
                        
                        if(xx < 0 || yy < 0 || xx >= n || yy >= n) {
                            continue;
                        }

                        // prob of (OR) is added together.    
                        totalProb += dp[k-1][xx][yy];
                    }

                    dp[k][i][j] = (double)totalProb/8;
                }
            }
        }

        return dp[moves][row][column];
    }

};



class Solution {
public:

    vector<vector<int>> directions = {{1,2},{1, -2}, {2, 1}, {2, -1},{-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};

    double knightProbability(int n, int moves, int row, int column) {

        vector<vector<double>> dp(n, vector<double>(n, 1));

        for(int k = 1; k <= moves; k++) {

            // used other array to store the current level information.
            vector<vector<double>> dp_copy(n, vector<double>(n, 0));

            for(int i = 0; i < n; i++) {

                for(int j = 0; j < n; j++) {

                    double totalProb = 0;

                    for(auto dir : directions) {
                        
                        int xx = dir[0] + i;
                        int yy = dir[1] + j;
                        
                        if(xx < 0 || yy < 0 || xx >= n || yy >= n) {
                            continue;
                        }

                        // prob of (OR) is added together.    
                        totalProb += dp[xx][yy];
                    }

                    dp_copy[i][j] = (double)totalProb/8;
                }
            }
            //swap for the next level.
            dp = dp_copy;
        }

        return dp[row][column];
    }

};