#include <bits/stdc++.h>
#include <cmath>
// // #define ll long long
// #define REP(i,n) for(int i = 0; i < n; i++)
// #define REP1(i,n) for(int i = 1; i <= n; i++)
// #define debug cout << "Ok" << endl

using namespace std;


// typedef pair<int,int> ii;
// typedef vector<ii> vii;
// typedef map<char,int> mci;
// typedef vector<int> vi;
// typedef vector<vi> vvi;

/*
==============================> Apporach <=============================================



*/

// ll gcd(ll a,ll b) {return b == 0 ? a : gcd(b,a%b);}
// ll lcm(ll a, ll b) {return (a * (b / gcd(a,b)));}





int main() {


    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("inputf.in","r",stdin);
    freopen("outputf.in","w",stdout);
    #endif

    int t; cin >> t;
    while(t--) {
        
        int n; cin >> n;

        unordered_map<int,int> horizontal;
        unordered_map<int,int> vertical;
        
        for(int i = 0; i < n; i++) {
            
            int x, y;
            cin >> x >> y;

            if(!horizontal.count(x))
                horizontal[x] = 1;

            if(!vertical.count(y))
                vertical[y] = 1;
        }

        cout << horizontal.size() + vertical.size() << endl;
    }


    return 0;
}

