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

Question : Fractional Knapsack
Topic : Scheduling, Greedy
Problems : https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#
/*
==============================> Explanation <=============================================
- Standard Problem 


*/


/*
==============================> Edge Case <=============================================


*/

class Solution
{
    public:

    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) {

        sort(arr, arr + n, [](Item a, Item b) {
            return (double)a.value/(double)a.weight > (double)b.value/(double)b.weight;
        });

        double res = 0;
        int i = 0;
        while(W > 0 && i < n) {
            if(W - arr[i].weight >= 0) {
                res += arr[i].value;
                W -= arr[i].weight;
            }
            else {
                res += (double)W * ((double)arr[i].value/arr[i].weight);
                W = 0;
                break;
            }
            i++;
        }

        return res;
    }

        
};
