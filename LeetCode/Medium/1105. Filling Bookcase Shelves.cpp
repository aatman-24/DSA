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

Question: 1105. Filling Bookcase Shelves
Topic : Top-Down Bottom-up Pattern=MCM Version Linear DP
Problems : https://leetcode.com/problems/filling-bookcase-shelves/


==============================> Explanation <=============================================
- Dp variant = MCM,

- Here clearly we don't know which set of books we can put together(where to put cut). So we
try at every place from (index, j) then choose which ever give the minimum height.

- But Second things here is that we also given the limit on width so we can not put books
so that exceeds. And also we choose the books in sequence. don't break the sequence if new book
don't place into the currrent shelf then create new shelf from that books.


1) Choice Diagram:
- Try to put the cut at every place between (index, books.size()). Which ever is give the minimum
we choose that one. And in the same shelf books height is the maximum height from all the books on 
that shelf. 


2) Base Case:
- N >= arr.size() -> return 0.(No books no height)


3) Recurrance Relation With Explanation: 

    int curLimit = 0, minimumHeight = INT_MAX, maxHeight = 0;

    for(int i = index; i < books.size(); i++) {

        if(books[i][0] + curLimit <= limitOnWidth) {

            // Height is maximum of all  book's height on the same shelf.
            maxHeight = max(maxHeight, books[i][1]);
            
            // add width on current limit.
            curLimit = books[i][0] + curLimit;
        
            // choose minimum height from all the cut.
            // Current shelf height is maximumHeightOn_current_shelf + nextState to arrange other books in such
            // way that it also give minimum height.
            minimumHeight = min(minimumHeight, maxHeight + minHeightShelves(i+1, books, limitOnWidth));
        }
        else

            // this clause is necessary because we can only take the books in sequence.
            break;
    }

    t[index] = mininumHeight;


3) Recurrance Relation: 

    int curLimit = 0, minimumHeight = INT_MAX, maxHeight = 0;

    for(int i = index; i < books.size(); i++) {

        if(books[i][0] + curLimit <= limitOnWidth) {

            maxHeight = max(maxHeight, books[i][1]);
            curLimit = books[i][0] + curLimit;

            minimumHeight = min(minimumHeight, maxHeight + minHeightShelves(i+1, books, limitOnWidth));
        }
        else
            break;
    }

    return t[index] = minimumHeight

==============================> Apporach and Time Complexity <=============================================

0) Brute Force take O(2^N).. Using Recursion...

1) Top-Down Bottom-up Pattern=MCM Version Linear DP
Time: O(N)
Space: O(N)

*/




class Solution {
public:
int t[1001];

int minHeightShelves(int index, vector<vector<int>> &books, int limitOnWidth) {
    
    if(index >= books.size())
        return 0;

    if(t[index] != -1)
        return t[index];

    int curLimit = 0, minimumHeight = INT_MAX, maxHeight = 0;

    for(int i = index; i < books.size(); i++) {

        if(books[i][0] + curLimit <= limitOnWidth) {

            maxHeight = max(maxHeight, books[i][1]);
            curLimit = books[i][0] + curLimit;

            minimumHeight = min(minimumHeight, maxHeight + minHeightShelves(i+1, books, limitOnWidth));
        }
        else
            break;
    }

    return t[index] = minimumHeight;
}


    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {

        memset(t, -1, sizeof(t));

        return minHeightShelves(0, books, shelfWidth);
    }
};


class Solution {
public:

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {

        int n = books.size();

        int dp[n+1];

        // base
        dp[n] = 0;

        for(int i = n - 1; i >= 0; i--) {
            

            // same as above.
            int curLimit = 0, minimumHeight = INT_MAX, maxHeight = 0;

            for(int j = i; j < n; j++) {

                if(books[j][0] + curLimit <= shelfWidth) {
            
                    maxHeight = max(maxHeight, books[j][1]);
                    curLimit = books[j][0] + curLimit;
                    minimumHeight = min(minimumHeight, maxHeight + dp[j+1]);
                }
                else {
                    break;
                }
            }

            dp[i] = minimumHeight;
        }


        return dp[0];
    }
};
