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

Question: 638. Shopping Offers
Topic : Top-Down Bottom-up Pattern=Bounded Knapsack
Problems : https://leetcode.com/problems/shopping-offers/

==============================> Explanation <=============================================
- Dp variant = Unbounded Knapsack,

- Either take it or don't take it.

- but here recursion brute force is easily passed.

State for the dp is -> [idx, needs]

==============================> Apporach and Time Complexity <=============================================

1) Brute Force Pattern=Bounded Knapsack
Time: O(N*M)
Space: O(N*M)

*/



class Solution {
public:

    bool isValid(vector<int> &offer, vector<int> &needs) {
        for(int i = 0; i < needs.size(); i++) {
            if(offer[i] > needs[i])
                return false;
        }
        return true;
    }


    int directPurchase(vector<int> needs, vector<int> price) {
        int total = 0;
        for(int i = 0; i < needs.size(); i++) {
            total += needs[i] * price[i];
        }
        return total;
    }

    int shoppingOffers(int idx, vector<int> &price, vector<int> &needs, vector<vector<int>> &special) {
        
        int res = directPurchase(needs, price);
        
        for(int i = idx; i < special.size(); i++) {
            
            vector<int> offer = special[i];
            
            if(isValid(offer, needs)) {
                
                vector<int> remaining(needs.size(), 0);

                for(int j = 0; j < needs.size(); j++) {
                    remaining[j] = needs[j]-offer[j];
                }

                res = min(res, offer[offer.size()-1] + shoppingOffers(i, price, remaining, special)); 
            }
  
        }

        return res;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int index = 0;
        return shoppingOffers(index, price, needs, special);
    }
};