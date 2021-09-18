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

Question: 475. Heaters
Topic : Binary Search
Problems : https://leetcode.com/problems/heaters/
==============================> Explanation <=============================================
N = House size
M = Heater size

Book Allocation Variation.
1) In first approach, from [0, 10^9] radius is find by binary search and selected
radius is valid is checked using greedy method in O(N).

2) Second Approach Vice versa, Calculate the right most and left most distance
of heater with respect to the current house. We choose the minimum of both leftmost
and rightmost for that house. And overall for all house we choose maximum of that.
In this finding nearest heater is performed using Binary Search.

3) Same Apporach is used above but rathar than finding nearest heater using
binary serach we performed using linear method.


==============================> Apporach and Time Complexity <=============================================
N = House size
M = Heater size

1) Binary Serach on House:
Time: O(KlogN)
Space: O(1)

2) Binary Serach on Heater:
Time: O(NlogM)
Space: O(1)

3) Sort + linear Way:
Time: O(NlogN) + O(MlogM) + O(M) 
Space: O(N)

*/

class Solution {
public:

    bool isPossible(vector<int> &house, vector<int> &heater, int r) {

        int n = house.size(), m = heater.size();
        int i = 0, j = 0;

        while(i < n && j < m) {

            if(heater[j] - r <= house[i] && house[i] <= heater[j] + r)
                i++;
            else
                j++;
        }

        // all houses is reached by that radius.
        return i == n;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {

        long low = 0, high = 10000000000, ans = 1;

        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        while(low <= high) {

            int mid = (low + high) >> 1;

            if(isPossible(houses, heaters, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};




class Solution {
public:

    int findRadius(vector<int>& houses, vector<int>& heaters) {

        int ans = INT_MIN;
        sort(heaters.begin(), heaters.end());

        for(auto house: houses) {
            int rad = findRad(house, heaters);
            ans = max(ans, rad);
        }

        return ans;
    }


    int findRad(int house, vector<int> &heaters) {

        int low = 0, high = heaters.size() - 1;
        int leftMostDist = INT_MAX, rightMostDist = INT_MAX;

        while(low <= high) {

            int mid = (low + high) >> 1;
            int heater = heaters[mid];

            if(heater == house)
                return 0;
            
            else if(heater > house) {
                rightMostDist = heater - house;
                high = mid - 1;
            }
            else {
                leftMostDist = house - heater;
                low = mid + 1;    
            }
        }

        return min(leftMostDist, rightMostDist);
    }
};



class Solution {
public:

    int findRadius(vector<int>& houses, vector<int>& heaters) {

        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        vector<int> res(houses.size(), INT_MAX);

        // For each houses find the nearest rightmost hearter
        for(int i = 0, j = 0; i < houses.size() && j < heaters.size(); ) {
            if(houses[i] <= heaters[j]) {
                res[i] = heaters[j] - houses[i];
                i++;
            }
            else j++;  
        }


        // For each houses find the nearest leftmost hearter
        for(int i = houses.size()-1, j = heaters.size()-1; i >= 0 && j >= 0; ) {
            if(houses[i] >= heaters[j]) {
                res[i] = min(res[i], houses[i] - heaters[j]);
                i--;
            }
            else j--;  
        }


        int ans = INT_MIN;
        for(int i = 0; i < res.size(); i++) {
            ans = max(ans, res[i]);
        }

        return ans;

    }
};