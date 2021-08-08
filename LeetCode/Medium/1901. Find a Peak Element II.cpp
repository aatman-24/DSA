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

Question : 1901. Find a Peak Element II
Topic : Binary Search
Problems : https://leetcode.com/problems/find-a-peak-element-ii/

==============================> Explanation <=============================================
Same Concept Find a Peak Element I(162. Find Peak Element). Where we find the any peak element into given 
array. But here we need to find in matrix.

What I did is wrong.
- Loop through the every row and find the peak element. And check wheather it is 
greater than above and below of that column. Which given wrong answer. Because
what i got the index of peak element in row is local peak value which maybe maximum
or not from the column-1, column+1 element. If it is not then you should find the
next maximum into the row. But here in my logic once the find any peak element 
it moves to the next row where i made mistake.


So solution is that, need to find local pick which is maximum from all the side 
while running the binary search. Don't try to first run the BS and then checking which
is wrong.

*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:
   
    // 1) O(N*M) -> LInear Search

    // 2) O(NlogM) -> Binary Search

    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int n = mat.size(), m = mat[0].size();

        for(int i = 0; i < n; i++) {

            int l = 0, h = m-1;

            while(l <= h) {

                int mid = (l + h) >> 1;
                
                int top = (i == 0) ? -1 : mat[i-1][mid];
                int bottom = (i == n-1) ? -1 : mat[i+1][mid];
                int left = (mid == 0) ? -1 : mat[i][mid-1];
                int right = (mid == m-1) ? -1 : mat[i][mid+1];


                int num = mat[i][mid];


                if(num > top && num > bottom && num > left && num > right) {
                    return {i, mid};
                }

                if(num < right) {
                    l = mid + 1;
                }
                else {
                    h = mid-1;
                }
            }
        }

        // return {-1, -1};    (Not Excute)
    }

};