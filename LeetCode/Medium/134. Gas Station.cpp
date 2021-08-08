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

Question : 134. Gas Station
Topic : Greedy, Prefix sum.
Problems : https://leetcode.com/problems/gas-station/
/*
==============================> Explanation <=============================================
- If car starts at A and can not reach B(found negative gas). 
Any station starting between A and B can not reach B. 
(B is the first station that A can not reach.)



-If the total number of gas is bigger than the total number of cost. There must be a solution.
(check via the prefix sum)

(Should I prove them?)

*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        // total_negative_gas is gas that is needed to reach the left elements from the current.
        // so whenever the gas goes to negative we add required gas to this.

        int start = 0, total_negative_gas = 0, current_gas = 0;

        for(int i = 0; i < gas.size(); i++) {

            // add remaining gas to the current_gas.
            current_gas += gas[i] - cost[i];


            if(current_gas < 0) {
                total_negative_gas += current_gas;  // we add negative gas required to total_negative_gas
                current_gas = 0;                    // set current_gas = 0.
                start = i + 1;                      // start = i + 1.
            }
        }

        // if total reamining gas is at last must be zero or positive.
        if(total_negative_gas + current_gas >= 0)
            return start;
        
        return -1;
    }
};