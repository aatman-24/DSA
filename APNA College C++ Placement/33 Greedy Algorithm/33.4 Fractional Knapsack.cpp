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
Question : 33.4 Fractional Knapsack

/*
==============================> Explanation <=============================================



*/

/*
==============================> Edge Case <=============================================

*/

bool sort_func(pair<int,int> &p1, pair<int,int> &p2) {
    return p1.first/p1.second > p2.first/p2.second;
}

int maxValuefromKnapsack(vector<int> weight, vector<int> values, int W) {

    vector<pair<int,int>> valWeight;
    for(int i = 0; i < weight.size(); i++) {
        valWeight.push_back({values[i], weight[i]});
    }

    sort(valWeight.begin(), valWeight.end(), sort_func);

    int maxValue = 0, i = 0;

    while(W) {
        if(W - valWeight[i].second >= 0) {
            W -= valWeight[i].second;
            maxValue += valWeight[i].first;
        }
        else {
            maxValue += ((valWeight[i].first / valWeight[i].second) * W);
            W = 0;
        }
        i++;
    }

    return maxValue;
}


int main() {

    vector<int> values = {40, 24, 30, 21, 12};
    vector<int> weights = {5, 4, 6, 7, 6};
    int W = 20;


    cout << maxValuefromKnapsack(weights, values, W) << endl; // output : 109 [40 + 24 + 30 + (15)]

    return 0;
}