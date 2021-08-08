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

Question : Matrix Median
Topic : Binary Search
Problems : https://www.interviewbit.com/problems/matrix-median/

==============================> Explanation <=============================================

Binary Serach Apply to the problem where search space is monotonicly increse.

Median is element which left and right elements are same.

So here we just count left element and find wheather current element is median or not.


Here for n = 1 -> How many number are less than or equal to 1 into given matrix -> n1
         n = 2 -> How many number are less than or equal to 2 into given matrix -> n2
         n = 3 -> How many number are less than or equal to 3 into given matrix -> n3

         so it is clear that n1 < n2 < n3.....

So it is monotonicly increase so yes here we can apply the binary search.

But How ?
Check this video..
    https://www.youtube.com/watch?v=63fPPOdIr2c&list=PLgUwDviBIf0qYbL4TBaEWgb-ljVdhkM7R&index=3


Logic is that we apply the binary search for space = [1, 10^9]. And for the current mid
count how many elements less than or equal to mid(actual mid) in given array.

As we know the median for the matrix is = (N * M) / 2 = (Total element / 2)

So we check the result of above one with (N*M) / 2. If it is less than or equal to that 
we decrease the space by low = mid + 1

otherwise high = mid - 1.

At last the result is. (low) because this is seperate the boundary.

Elements are less than or Equal to X based on that binary search apply.




2) How to count the elements which are less than mid into given matrix.
    
    Row by Row:

    - Binary Search 
        use built_in upper_bound() which points to location which is greater than mid.

    - Manually perform the binary serach.
        Same Way. Check the Code.

Time Complexity = O(log2(2^32) * N * logM) -> apply binary search to every row of M column.

                = O(NlogM)

Space Complexity = O(1).



*/


/*
==============================> Edge Case <=============================================


*/

int countSmallerThanEqualToMid(vector<int> &row, int mid) {
    int l = 0, h = row.size() - 1;

    while(l <= h) {

        int md = (l + h) >> 1;

        if(row[md] <= mid) {
            l = md + 1;
        }
        else {
            h = md - 1;
        }
    }

    return l;
}


int Solution::findMedian(vector<vector<int> > &A) {
    int low = 1;
    int high = 1e9;
    int n = A.size();
    int m = A[0].size();

    while(low <= high) {

        int mid = (low + high) >> 1;
        int cnt = 0;        // median Count how many numbers all less than A[mid] into every rows. 

        for(int i = 0; i < n; i++)  {
            cnt += countSmallerThanEqualToMid(A[i], mid);
        }

        if(cnt <= (n*m)/2) low = mid + 1;
        else high = mid - 1;
    }

    return low;
}
