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

Question : 1338. Reduce Array Size to The Half
Topic : Array, Greedy
Problems : https://leetcode.com/problems/reduce-array-size-to-the-half/
*/


class Solution {
public:

    bool sort_func(ii &p1, ii &p2) {
        if(p1.first == p2.first) return p1.second < p2.second;
        return p1.first > p2.first;
    }

    // O(N*logN) - O(N)
    int minSetSize(vector<int>& arr) {

        mii mp;
        int n =  arr.size();
        REP(i, n) mp[arr[i]]++;
        int set = 0;
        vii res;
        for(auto i : mp) {
            if(i.second >= n/2) {set = 1;}
            res.push_back({i.second, i.first});
        }
        if(!set) {
            sort(res.begin(), res.end(), sort_func);
            int sum = 0, i = 0;
            while(sum < n/2) {
                sum += res[i].first;
                i++; 
            }
            return i;
        }
        return 1;       
    }


    // O(N) - O(N).
    int minSetSize(vector<int>& arr) {

        memset(occ, 0, sizeof(occ));

        int n = arr.size();
        REP(i, n) occ[arr[i]]++;

        vi count;
        REP(i,n) {
            if(occ[arr[i]] != -1) {
                count.push_back(occ[arr[i]]);
                occ[arr[i]] = -1;
            }
        }
        sort(count.begin(), count.end(), greater<int>());
    
        int sum = 0, i = 0;
        while(sum < n/2) {
            sum += count[i];
            i++; 
        }
        return i;     

    }
};
