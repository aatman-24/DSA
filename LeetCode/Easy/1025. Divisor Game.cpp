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

Question: 1025. Divisor Game
Topic : DP
Problems : https://leetcode.com/problems/divisor-game/

==============================> Explanation <=============================================

- Given that play optimally it means whatever first i found for which (n % i == 0) then player must chose that one.
And here we have option to choose i, 0 < i < n, means for i = 1 every time (n % 1 == 0) is true so every player
choose i = 1. (in given question that's why it is bad question).

=>> Choice Diagram -> N = if(N % i == 0), Go (N-i) only once.

==> Base Case -> N == 1 && aliceTurn = 1 Return 0. (Alice lose)
              -> N == 1 && aliceTurn = 1 Return 1. (Alice Win)

==> Recurrance Relation: F(N) = F(N % i == 0, return F(N-i))
                              = F(N % 1 == 0, return F(N-1))
                
I solved using proper DP(General Case), F(N) = F(N-1)
==============================> Apporach and Time Complexity <=============================================
1) Bottom-UP DP:
Time: O(N)
Space: O(N)(Memorization)

2) One Statement:
Time: O(1)
Space: O(1)

*/

class Solution {
public:

    int t[1001];

    bool gamePlay(int n, int aliceTurn) {

        // base condition

        // If at last aliceTurn and n == 1 then alice lose.
        if(n <= 1 && aliceTurn)
            return 0;

        // If Bob has last turn and n == 1 then alice win.
        if(n <= 1 && !aliceTurn)
            return 1;

        if(t[n]!= -1)
            return t[n];

        bool win_alice = false;

        for(int i = 1; i <= n/2 && !win_alice; i++) {

            if(n % i == 0) {

                if(t[n-i] == -1)
                    t[n-i] = gamePlay(n-i, !aliceTurn);

                if(t[n-i])
                    win_alice = true;
            }
        }

        return t[n] = (int)win_alice;
    }


    bool divisorGame(int n) {

        memset(t, -1, sizeof(t));

        return (bool)gamePlay(n, 1);
    }
};


class Solution {
public:
    bool divisorGame(int n, bool aliceTurn=true) {
        if(n == 1 && aliceTurn)
            return false;
        if(n == 1 && !aliceTurn)
            return true;
        return divisorGame(n-1, !aliceTurn);
    }

};


class Solution {
public:
    bool divisorGame(int n) {

        // if alice start with odd number then 1 goes to the alice. If even number then last 1 goes to Bob.
        return !(n % 2);
    }

};