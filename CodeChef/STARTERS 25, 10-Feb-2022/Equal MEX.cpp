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


const int MAX = 100001;

int mp[100001];

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

        memset(mp, 0, sizeof(mp));

        for(int i = 0; i < 2 * n; i++) {
            int num; cin >> num;
            mp[num]++;
        }

        for(int i = 0; i < MAX; i++) {
            if(mp[i] == 0) {
                cout << "YES" << endl;
                break;
            }
            else if(mp[i] == 1) {
                cout << "NO" << endl;
                break;
            }
        }

    }

    return 0;
}

