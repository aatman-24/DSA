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

Question : 48. Rotate Image
Topic : Array, Matrix
Problems : https://leetcode.com/problems/rotate-image/

/*
==============================> Explanation <=============================================
Clock Wise 90 Degree -> Reverse the matrix by array + Symmentry Roataion
AntiClock Wise 90 Degree -> Reverse all the array + Symmentry Roataion


==============================> Edge Case <=============================================
1) Matrix Rotation:
Time:O(N^2)
Space:O(1)

*/

class Solution {
public:

    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

/*
 * clockwise rotate (90 Degree)
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/

    void rotate(vector<vector<int>> &matrix) {

        // reverse array order
        reverse(matrix.begin(), matrix.end());
        
        // swap symmentry
        for(int i = 0; i < matrix.size(); i++) {

            for(int j = i+1; j < matrix[i].size(); j++) {

                swap(matrix[i][j], matrix[j][i]);

            }

        }
    }

/*
 * anticlockwise rotate(90 Degree)
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/

    void anti_rotate(vector<vector<int> > &matrix) {

        //reverse elements
        for (auto vi : matrix) reverse(vi.begin(), vi.end());


        // swap symmentry
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[i].size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
}
};