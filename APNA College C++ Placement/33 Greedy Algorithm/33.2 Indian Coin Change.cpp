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
Question : 33.2 Indian Coin Change 

/*
==============================> Explanation <=============================================
Choose Whichever coins is most promising at any situation. (Greedy)


*/

/*
==============================> Edge Case <=============================================

*/

// return the minimum num of coin.
int minCoin(int value) {

    int denomination[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int n = sizeof(denomination) / sizeof(int);

    sort(denomination, denomination+n, greater<int>());

    int i = 0, coin = 0;
    while(value) {
        while(value - denomination[i] >= 0) {
            value -= denomination[i];
            coin++;
        }
        i++;
    }
    return coin;
}


int main() {

    cout << minCoin(258) << endl; // output : 5 [200, 50, 5, 2, 1]

    return 0;
}