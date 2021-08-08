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

Question : 240. Search a 2D Matrix II
Topic : Binary Search
Problems : https://leetcode.com/problems/search-a-2d-matrix-ii/

==============================> Explanation <=============================================




Apporach 1) O(N*M) Linear Search.

Appoorach 2) O(logN) (binary Search)

Apporach 3) O(N+M) logic or observation.
*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:

    int upperBound(vector<int> &arr, int target) {

        int l = 0, h = arr.size() - 1;

        while(l <= h) {

            int mid = (l + h) >> 1;

            if(arr[mid] <= target) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }

        return l;
    }


    // Binary Search = O(NlogM)
    // I used upper bound to eliminate the extra col which can not have the target.
    // But in worst case also we have to visit every column and apply binary search.
    // so it is same as pick every row/columna and perform BST. But using upper_bound
    // get optimized.
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size(), n = matrix[0].size();

        int idx = upperBound(matrix[0], target) - 1;
        
        cout << idx << endl;

        while(idx >= 0) {

            if(matrix[0][idx] <= target && target <= matrix[m-1][idx]) {

                int l = 0, h = m - 1;

                while(l <= h) {

                    int mid = (l + h) >> 1;

                    if(matrix[mid][idx] == target) return true;

                    if(matrix[mid][idx] < target) {
                        l = mid + 1;
                    }
                    else {
                        h = mid - 1;
                    }
                }

            }
            idx--;
        }

        return false;
    }




    // O(N+M)
    // concept is that, we start with top right corner. Every element in the row is
    // less than that element and every element in the column greater than that element
    // we use the same logic.

    // if we find target < matrix[row][col]. It means that we can not find the target 
    // into the current column. Because matrix[row][col] is the lowest element into
    // the column. So we perform--.

    // if we find target > matrix[row][col]. It means that we can not find target into the 
    // current row reason is matrix[row][col] is the largest element into row. So increase 
    // the row++. 

    // if any time row > matrix.size() && col <= 0 means we did not find target. and 
    // if matrix[row][col] == target means we find the target. 

    // Time = O(N+M) Every time we shrink by the row or column. 

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if(matrix.size() < 1 || matrix[0].size() < 1) {
            return false;
        }

        int row = 0, col = matrix[0].size() - 1;

        while(row <= matrix.size()-1 && col >= 0) {

            if(matrix[row][col] == target) {
                return true;
            }
            else if(target < matrix[row][col]) {
                col--;
            }
            else {
                row++;
            }
        }

        return false;

    }
};