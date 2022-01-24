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

Question: 292. Nim Game

Topic : Game, DP, Pattern

Problems : https://leetcode.com/problems/nim-game/

==============================> Explanation <=============================================

Assume Two players = Alice(ME), Opponent = Bob

Brute Force: Every player try to win. If player found any possiblity to win the move then he will choose that. 
             Example.. for n = 3(T), 4(F), 5(T)... then current player try to win the game and choose 3 or 5 as move.
    
            - But What we return to the recursive function call.....
                
                Alice -> Bob; If bob win in all the possiblity then he will return false for Alice.
                            ; If bob lose if any one of them then it will return true for alice. So alice make that move.
            
            So come up with this conclusion,

            -   
     
A) Choice Diagram: If current player win all the possiblity then he will winner and return false for opponent. Any of one
                   Possiblity he will lose then it will return true for opponent to make that move.

B) Base Case: N <= 3 return true.

C) Recurrance Relation:

        if(canWinNim(n-1) && canWinNim(n-2) && canWinNim(n-3))
                return false;
        return true;


Pattern: 

- If you see the constraint, 1 <= n <= 2^31 - 1.. then you directly got the idea DP is not option and also O(N) is also
not idea here.

So Need O(1) solution....

Pattern found is that, 

    For N = 4, 8, 12, 16.... It will return false.

    Why ?

    - As we dicussed when all possiblity for current player win then they return false for Opponent...

    When N = 4,    N - 1 = 3, N - 2 = 2, N - 3 = 1 (All this three return true).

    So we return false for opponent or result.

    Same for N = 8, (7,6,5) All return True...so we return false for n = 8..

Now you see the pattern,

    for only n = 4, 8, 12 -> between number are (5, 6, 7) -> (9, 10, 11) this all set which can not have any number which return 
    false for single time.

So very simple,

    if n is multiple of 4 then we return false.
    else return true.

    return !(n % 4 == 0)


==============================> Apporach and Time Complexity <=============================================

1) Two Pointer/logic
Time: O(N)
Space: O(1)

*/


// TLE DP Top-Down
class Solution {

public:

    unordered_map<int, bool> mp;
    
    bool canWinNim(int n) {
    
        if(n <= 3)
            return true;
        
        if(mp.count(n))
            return mp[n];

        if(canWinNim(n-1) && canWinNim(n-2) && canWinNim(n-3))
            return mp[n] = false;
        
        return mp[n] = true;
    }
};


// TLE DP Bottom-up.
class Solution {

public:

    bool canWinNim(int n) {

        if(n <= 3)
            return true;

        unordered_map<int,bool> mp;

        mp[0] = mp[1] = mp[2] = mp[3] = true;

        for(int i = 4; i <= n; i++) {

            if(mp[i-1] && mp[i-2] && mp[i-3])
                mp[i] = false;
            else
                mp[i] = true;
        }

        return mp[n];
    }
};



// Pattern.
class Solution {

public:

    bool canWinNim(int n) {

        if(n <= 3)
            return true;

        return !(n % 4 == 0);
    }
};
