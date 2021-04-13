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

Question : 1314. Matrix Block Sum
Topic : DP, Kadane
Problems : https://leetcode.com/problems/matrix-block-sum/
*/

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

Question : 1823. Find the Winner of the Circular Game
Topic : Array, Queue, Trick
Problems :https://leetcode.com/problems/find-the-winner-of-the-circular-game/
*/

// O(N^2)
class Solution {
public:
    int findTheWinner(int n, int k) {
                vi arr(n, 0);
        int cnt = n;
        int i = 0;
        while(cnt != 1) {
            while(arr[i] == -1) {
                i = (i+1) % n;
            }
            int shift = k - 1;
            while(shift != 0) {
                if(arr[i] != -1) shift--;
                i = (i + 1) % n;
            }
            
            while(arr[i] == -1) {
                i = (i + 1) % n;
            }
            // cout << "KILLED " << i << endl;
            arr[i] = -1; cnt--;
        }

        int ans;
        REP(i,n) if(arr[i] != -1) ans = i+1;
        return ans;
    }
};


// O(N^2)
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size()!=1){
            int x=k;
            while(x>1){
                int r=q.front();
                q.pop();
                q.push(r);
                x--;
            }
            q.pop();
        }
        return q.front();
    }
};

// O(N)
int findTheWinner(int n, int k) {
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res = (res + k) % i;   // last winner index = (last winner index + k) % i
    return res + 1; 
}