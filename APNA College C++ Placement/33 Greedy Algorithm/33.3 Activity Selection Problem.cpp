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
Question : 33.3 Activity Selection Problem 

/*
==============================> Explanation <=============================================
sort the activity based on whichever finished first. And take into greedy manner the max number of activity selection
is answer.

- remember the number of activity remains same.But it possible same number of activity but differnt
is also answer.
*/

/*
==============================> Edge Case <=============================================

*/

// maximum number of activity can be performed.
int maxNumberOfActivity(vector<vector<int>> acitivity) {

    sort(acitivity.begin(), acitivity.end(), [&](vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    });

    int totalAcitivity = 1;
    int endTime = acitivity[0][1]; // take first one directly.


    for(int i = 1; i < acitivity.size(); i++) {

        if(endTime <= acitivity[i][0]) {
            totalAcitivity++;
            endTime = acitivity[i][1];
        }

    }

    return totalAcitivity;
}


int main() {

    vector<vector<int>> acitivity = {{1, 3}, {2, 5}, {3, 6}, {5, 7}, {9, 11}, {7,8}, {8,9}};

    cout << maxNumberOfActivity(acitivity) << endl; // output : 5 [0, 2, 4, 5, 6]

    return 0;
}`