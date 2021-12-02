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

Question: 605. Can Place Flowers
Topic : Greedy
Problems : https://leetcode.com/problems/can-place-flowers/

==============================> Explanation <=============================================

- Greedily check wheather, we can put the plot at given index,if yes then we put it.

==============================> Apporach and Time Complexity <=============================================

1) Greedy
Time: O(N)
Space: O(1)

*/


class Solution {

public:

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        

        for(int i = 0; i < flowerbed.size(); i++) {
           
            if(flowerbed[i] == 0) {

                bool possible = true;

                if(i > 0 && flowerbed[i-1] == 1)
                    possible = false;

                if(i < flowerbed.size() - 1 && flowerbed[i+1] == 1)
                    possible = false;

                if(possible) {
                    flowerbed[i] = 1;
                    n--; 
                }
            }
        }

        return n <= 0;
    }
};