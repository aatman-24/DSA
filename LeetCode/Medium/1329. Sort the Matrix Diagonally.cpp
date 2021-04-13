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

Question : 1329. Sort the Matrix Diagonally
Topic : Sort, 2D-Array
Problems : https://leetcode.com/problems/sort-the-matrix-diagonally/solution/
*/


// Time Complexity  ((M+N) * M*N*log(min(M,N))))
class Solution {
public:
    

    void sortDiagonal(vector<vector<int>>& mat, size_t row, size_t col) {
            size_t m = mat.size();
            size_t n = mat[0].size();

            // create a min-heap to store the diagonal
            priority_queue<int, vector<int>, greater<int>> diagonal;

            size_t diagonal_length = min(m - row, n - col);
            // Put values on this diagonal into the heap.
            for (size_t i = 0; i < diagonal_length; i++) {
                diagonal.push(mat[row + i][col + i]);
            }

            // Put values on heap back into this diagonal
            for (size_t i = 0; i < diagonal_length; i++) {
                mat[row + i][col + i] = diagonal.top();
                diagonal.pop();
            }
    }

    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int tmp;
        int xIndex = 0, yIndex =3;
        for(int i = 0; i < n; i++) {
            sortDiagonal(mat, i, 0);
        }

        for(int j = 1; j < m; j++) {
            sortDiagonal(mat, 0, j);
        }
        
        return mat;
    }
};

int main() {

	Solution ob;
    vvi mat = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};
    string res=  ob.diagonalSort(mat);
    cout << res << endl;
}