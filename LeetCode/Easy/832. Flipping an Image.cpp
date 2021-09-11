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
d
/*
==============================> Description <=============================================

Question : 832. Flipping an Image
Topic : matrix
Problems : https://leetcode.com/problems/flipping-an-image/

==============================> Explanation <=============================================


*/


/*
==============================> Edge Case <=============================================



*/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {

        int N = image[0].size();

        // toggle
         for(int row = 0; row < N; row++) {
            for(int col = 0; col < (N/2); col++){
                int temp = image[row][col];
                image[row][col] = image[row][N-1-col];
                image[row][N-1-col] = temp;
            }

        }

        // invert
         for(int row = 0; row < N; row++) {
            for(int col = 0; col < N; col++){
                image[row][col] = 1 - image[row][col];
            }
        }

        return image;
    }


    // O(N^2) - O(1)
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {

        // both together.
        for(auto& row: image) {
            reverse(row.begin(), row.end());
            for(auto& val: row)
                val = 1 - val;
        }

        return image;

    }
};