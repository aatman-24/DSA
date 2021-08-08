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

Question : 1605. Find Valid Matrix Given Row and Column Sums
Topic : Greedy
Problems : https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/
/*
==============================> Explanation <=============================================
- A[i][j] = min(rowSum[i], colSum[j])
    rowSum[i] -= A[i][j]; (whatever minimum between of them subtract also from it.)
    colSum[i] -= A[i][j];

Why Greedy ?

- When we at A[i][j] that time either we will take rowSum[i] or colSum[j]. But
here mention that non-negative matrix that's why we choose the minimum of
them and one of them become zero which ever is minimum.

- sum(rowSum) = sum(ColSum) means there are given that such matrix is 
formed you just need to find that matrix.

- At last rowSum = {0} and colSum = {0}. It is not possbile have entry > 0
into this array.



Time = O(N*M)
Space = O(1)
*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {

        int n = rowSum.size(), m = colSum.size();

        vector<vector<int>> res(n,vector<int>(m,0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // Take greedliy which is minimum. Because after this step
                // either rowSum[i] or colSum[j] become zero.
                int min_value = min(rowSum[i], colSum[j]); 
                
                res[i][j] = min_value;
                rowSum[i] -= min_value;
                colSum[j] -= min_value;
            }
        }

        return res;
    }
};