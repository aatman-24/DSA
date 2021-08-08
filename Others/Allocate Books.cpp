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

Question : Allocate Books
Topic : Binary Search
Problems : https://www.interviewbit.com/problems/allocate-books/

==============================> Explanation <=============================================
https://www.youtube.com/watch?v=gYmWHvRHu-s&list=PLgUwDviBIf0qYbL4TBaEWgb-ljVdhkM7R&index=8
*/


/*
==============================> Edge Case <=============================================

*/


// check allocation is possible or not.
bool isAllocationPossible(vector<int> &A, int B, int barrier) {

    int allocatedStudent = 1, pages = 0;

    for(int i = 0; i < A.size(); i++) {

        if(A[i] > barrier) return false;

        if(pages + A[i] > barrier) {
            allocatedStudent += 1;
            pages = A[i];
        }
        else {
            pages += A[i];
        }
    }

    if(allocatedStudent > B)
        return false;

    return true;
}


int sumOfPages(vector<int> &A) {

    int pages = 0;
    for(int page: A) {
        pages += page;
    }

    return pages;
}

int findMinPages(vector<int> &A) {
    int min = INT_MAX;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] < min) 
            min = A[i];
    }
    return min;
}


int Solution::books(vector<int> &A, int B) {

    // If student is greater than books.(Not allowed to share one books page with two student).
    if(A.size() < B) return -1;

    int low = findMinPages(A), high = sumOfPages(A), res=-1;

    while(low <= high) {

        int mid = (low + high) >> 1;

        if(isAllocationPossible(A, B, mid)) {
            res = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }

    }   

    return res;
}