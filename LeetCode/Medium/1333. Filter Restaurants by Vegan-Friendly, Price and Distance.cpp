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

Question : 1333. Filter Restaurants by Vegan-Friendly, Price and Distance
Topic : Array
Problems : 1333. Filter Restaurants by Vegan-Friendly, Price and Distance
*/

// O(NlogK)
class Solution {
public:
    
    static bool sort_fun(ii &p1, ii &p2) {
        if(p1.second == p2.second) return p1.first > p2.first;
        return p1.second > p2.second;
    }
    
    
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        int n = restaurants.size();
        
        bool checkVegan = false;
        if(veganFriendly == 1){
            checkVegan = true;
        } 

        vii filtered;
        for(int i = 0; i < n; i++) {
            if((!checkVegan || restaurants[i][2] == 1) && restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance) {
                filtered.push_back({restaurants[i][0], restaurants[i][1]});
            }
        }


        sort(filtered.begin(), filtered.end(), sort_fun);

        vi ans;
        for(int i = 0; i < filtered.size(); i++) {
            ans.push_back(filtered[i].first);
        }

        return ans; 
    }
};