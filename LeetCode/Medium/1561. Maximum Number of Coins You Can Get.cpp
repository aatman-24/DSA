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

Question : 1561. Maximum Number of Coins You Can Get
Topic : Greedy
Problems : https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
/*
==============================> Explanation <=============================================
Greedy -> Because we can not trick alice to have small amount pile. Because he is going
to choose first and he always take maximum.

suppose = [9,8,7,6,5,1,2,3,4]

after sorting = [9 8 7 6 5 4 3 2 1]

so what we do is, we make triplet we choose first two from left and 
last one from the right one for bob.


9 8 1 -> 8
7 6 2 -> 6
5 4 3 -> 3

We can not trick the alice. but we can trick the bob. Bob has no choise he 
should take the remaining one.


Time = O(N*M)
Space = O(1)
*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:
    int maxCoins(vector<int>& piles) {

        // sort the piles and take maximum after the alice.
        sort(piles.begin(), piles.end(), greater<int>());

        int res = 0;

        // Total 3 person is playing and every time we have to choose one
        // piles so my turn is total = piles.size() / 3 times.
        int  myTurn = piles.size() / 3;

        // start with 1 index piles. Because 0 index pile is taken by alice.
        int i = 1;
        
        while(n--) {
           res += piles[i];
            i += 2;
        }
        
        return res;
    }

};