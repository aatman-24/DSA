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

Question : 1578. Minimum Deletion Cost to Avoid Repeating Letters
Topic : Greedy
Problems : https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/
/*
==============================> Explanation <=============================================
- Group of continuous element we keep the greatest cost elemeent and delete all
other element.

- we can use keep track of cost += "total cost of group" - "maximum of group".

*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:


    int minCost(string s, vector<int>& cost) {

        int cost_t = 0, min_cost;

        for(int i = 0; i < s.size() - 1; ) {

            if(s[i] == s[i+1]) {

                min_cost = cost[i];

                // keep track of min_cost
                // if (i+1) element is same then cost[i+1] is
                // greater than min_cost then add min_cost to the
                // cost and cost[i+1] becomes minCost;

                // but if min_cost is greater than cost[i+1] then 
                // directly add the cost[i+1] to the total cost.
                // min_cost remain unchanged.
                while(i + 1 < s.size() && s[i] == s[i+1]) {

                    if(min_cost < cost[i+1]) {
                        cost_t += min_cost;
                        min_cost = cost[i+1]; 
                    }
                    else {
                        cost_t += cost[i+1];
                    }
                    i++;
                }
            }
            else {
                i++;
            }
        }

        return cost_t;
    }


    // O(N) - O(1)
    int minCost(string s, vector<int>& cost) {
        int res = 0, max_cost = 0, sum_cost = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (i > 0 && s[i] != s[i - 1]) {
                res += sum_cost - max_cost; // cost of group - max element cost 
                sum_cost = max_cost = 0;
            }
            sum_cost += cost[i];
            max_cost = max(max_cost, cost[i]);
        }
        res += sum_cost - max_cost;
        return res;
    }

}