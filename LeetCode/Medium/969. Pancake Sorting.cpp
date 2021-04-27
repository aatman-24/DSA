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

Question : 969. Pancake Sorting
Topic : Array
Problems : https://leetcode.com/problems/pancake-sorting/
*/

/*

- Find the Max Ele.
- reverse the arr [0:max_index] max_index -> max number's index.
- reverse the arr [0:last_index] reverse all arr so max number can be last this time and decrease
the last_index every time.

*/


// O(N^2).
class Solution {
public:

vector<int> pancakeSort(vector<int>& arr) {
    
    vi res;
    for(int x = arr.size(); x > 0; x--) {
        int i = 0;
        while(i < x && arr[i] != x) {
            i++;
        }
        reverse(arr.begin(), arr.begin() + i + 1); // here for adding max element i+1.
        res.push_back(i+1);

        reverse(arr.begin(), arr.begin() + x); // reverse the arr until x.
        res.push_back(x);

    }

    return res;

}
};
