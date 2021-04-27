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

Question : 1375. Bulb Switcher III
Topic : Array
Problems : https://leetcode.com/problems/bulb-switcher-iii/
*/


class Solution {
public:

    // Simulation O(N^2) - O(N). (Haven't descirbed here).


    // O(N) - O(1).
    int numTimesAllBlue(vector<int>& light) {
        int highIndexBlubOn = 0, cnt = 0;
        int n = light.size();
        for(int blubOn = 0; blubOn < n; blubOn++) {
            highIndexBlubOn =  max(light[blubOn], highIndexBlubOn);
            if(highIndexBlubOn == blubOn + 1) cnt++;
        }
        return cnt;
    }
};