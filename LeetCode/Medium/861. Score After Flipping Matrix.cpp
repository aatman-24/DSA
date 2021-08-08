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

Question : 861. Score After Flipping Matrix
Topic : 2DArray, Binary Number
Problems : https://leetcode.com/problems/score-after-flipping-matrix/
/*
==============================> Explanation <=============================================
https://leetcode.com/problems/score-after-flipping-matrix/discuss/143812/C%2B%2BJava-From-Intuition-Un-optimized-code-to-Optimized-Code-with-Detailed-Explanation

How to get matrix such that its row binary sum become greater ?

Read above discuss solution madatory.

In short Algorithm,

- First number of any binary number should be 1. Because 1000 > 0111.
    So If any row first number is not 1. Then we filp the row.

- Now we can not filp the row so now time for column.

- After getting first column as one. For any column should contain as many as 1 then it increase
the sum. So what we do is ,
    - count total number of 1 and total number of 0 for any column.
    - If column contain more 0 then 1. We again the filp the column.

- At last we just take the sum of all binary num.


Optimizied solution working:

- Here we first take sum of every number(row) with first bit as 1.

ans += (1 << (n-1)) * m; [For N-1 length number and total m number]

- After that we traverse all the column one by one starting from the 1.
And every column we compare the element with first column and see how many are same 
and how many are differnt. Using same variable.

(1-1) = add into count. 
(0-0) = add into count. Bcz after filping the row it become (1-1).
(1-0) | (0-1) = don't count it.


Now if same(number of 1) < (m - same)[number of 0] then we filp the column. But here we did not
do in real. Because we sum the number into column wise not row wise.

If number of 1 = max(same, m - same).

Example...

1 1 0 0
0 1 0 0
0 0 1 1

So for the second column = number of 1 = 2

sum += (n(4) - 1 - j(1)) * number of 1
    += (2) * 2
    += 4

That's how second solution work.
This is greedy technique and always works.


*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:
    void filpRow(vector<vector<int>> &A, int row, int n) {
        for(int j = 0; j < n; j++) {
            A[row][j] = A[row][j] ? 0 : 1;
        }
    }

    void filpCol(vector<vector<int>> &A, int col, int m) {
        for(int i = 0; i < m; i++) {
            A[i][col] = A[i][col] ? 0 : 1;
        }
    }

    // O(N*M) - O(N) #N = total column
    int matrixScore(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();
        vector<int> col(n,0);

        for(int i = 0; i < m; i++) {

            // First column should be 1 for every row. If it is not filp it.
            if(A[i][0] == 0)
                filpRow(A, i, n);

            // count total number of set bit.
            for(int j = 0; j < n; j++) {
                if(A[i][j] == 1) {
                    col[j]++;
                }
            }
        }


        // If col[j] contain 0 > col[j] contain 1 then we filp this column.
        for(int j = 0; j < n; j++) {
            if(col[j] <= m/2) {
                filpCol(A, j, m);
            }
        }


        // sum all the row as binary number.
        int ans = 0, sum;
        for(vector<int> v: A) {
            sum = 0;
            for(int j = 0; j < n; j++) {
                if(v[j] == 1) {
                    sum += pow(2, n-1-j);
                }
            }
            ans += sum;
        }


        return ans;
    }   


    // O(N*M) - O(1)
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size(), ans = 0;

        // Add 1000 + 1000 + 1000. First column of every row. Because as our algorithm we
        // try to make first column as 1 by filping the row if it is not.
        ans += (1 << (n-1)) * m;

        for(int j = 1; j < n; j++) {


            // same compare for currnet column with first column. How many of them are same ?
            // 0-0 and 1-1 are same. (if 0-0 then we filp the row both are become 1-1)
            // if(1-1) then don't need to anything just count it.
            int same = 0;
            for(int i = 0; i < m; i++) {
                if(A[i][0] == A[i][j]) same++;
            }

            // now we choose weather to filp the jth column or not.
            // if(same < m - same) filp the column. So we choose (m - same) otherwise same.
            ans += (1 << (n-1-j)) * max(same, m - same);
        }

        return ans;

    }
};