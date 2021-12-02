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

Question: 464. Can I Win
Topic : Top-Down Pattern=StateDP
Problems : https://leetcode.com/problems/can-i-win/

==============================> Explanation <=============================================
Dp variant = State DP.

Here, Each player add the choose number into the total, and adding into the score exceed or equal the target
number that means this player won.

- Idea is that, we try all the numbers from [1, maxChoosableInteger]. And see the wheather choosing that
number return false(opponent lost the game) then we choose that number if it return true(opponent win) then 
we don't choose that. 

- After all the numbers [1, maxChoosableInteger] return true then we return false at the end. Current player can
not win the game.


But Here is given that we don't use the same number again...

- So for that we can use the vector<int> + Backtracking...

- Here range is between [1, 20] then we also can use bit manipulation for that.. (Here).

- We keep track of target sum.


1) Choise Diagram: Above.

    Try all the numbers i -> [1, Upto]

    if(ith number is not taken)

        try ith number, and check it exceed or equal to the target OR choosing that number opponent lose.

2) Base Case: total <= i + 1... return true. (exceed or equal)

3) Recurrance Relation:
    
    - check in code.

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern=StateDP
Time: O(2^N * N)
Space: O(2^N  * N)

*/



class Solution {
public:
    
    unordered_map<int, bool> mp;

    bool canIWin(int cur, int upto, int total) {
        
        if(mp.count(cur))
            return mp[cur];
        
        for(int i = 0; i < upto; i++) {

            if((cur & (1 << i)) == 0) {
                
                if(total <= i + 1)
                    return mp[cur] = true;

                // If the next player return true for the next state we don't use this state, 
                // if it return false then we return true. 
                if(!canIWin(cur | (1 << i), upto, total - i - 1))
                    return mp[cur] = true;
            }
        }

        return mp[cur] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {

        int maxSum = (maxChoosableInteger * (maxChoosableInteger + 1)) >> 1;

        if(maxSum < desiredTotal)
            return false;

        if(desiredTotal <= 1)
            return true;

        int state = 0;

        return canIWin(state, maxChoosableInteger, desiredTotal);
    }

};