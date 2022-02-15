#include <bits/stdc++.h>
#include <cmath>
#define ll long long
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
        
        ll x, m; 
        cin >> x >> m;

        ll inv = 1, cur = 0, count = 0, j;

        while(m--) {

            if(inv < x) {
                cur += inv;
                inv = cur;
            }
            else {
                break;
            }
        }

        count = cur >= x ? 1 : 0;

        cout << m + count + 1 << endl;
    }

    return 0;
}

