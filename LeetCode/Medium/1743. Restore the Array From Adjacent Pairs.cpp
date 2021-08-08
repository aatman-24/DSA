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

Question : 1743. Restore the Array From Adjacent Pairs
Topic : Graph, DFS, Adjancency List
Problems : https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/

/*
==============================> Explanation <=============================================
Observation:

- Last and First element frequency is one so it is either start or end of array.
- What we do?
    - Create map to identify the neighbour of the given integer.
    - After that find start point. whose neighbour is 1.
    - [start_point, negibour_of_start_point, .... , start_point|end_point]
        After that we find the next element, by checking the neighbour of negibour_of_start_point which is
        not left neighbout.

    - Until we found element which has one neighbour which is last.
    Graph, DFS Problem.
*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
    public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {

        map<int, vector<int>> mp;
        vector<int> arr;

        // Add pair[0] -> {pair[1]} and also pair[1] -> {pair[0]}
        for(vector<int> pair: adjacentPairs){
            mp[pair[0]].push_back(pair[1]);
            mp[pair[1]].push_back(pair[0]);
        }

        // Found the element which has only one size vector because 
        // it is either end or begin of the array.
        for(auto p: mp) {
            if(p.second.size() == 1) {
                arr.push_back(p.first);
                arr.push_back(p.second[0]);
                break;
            }
        }

        int index = 1;
        while(true) {

            // Last element.
            if(mp[arr[index]].size() == 1)
                break;

            if(mp[arr[index]][0] != arr[index-1]) {
                arr.push_back(mp[arr[index]][0]);
            }
            else {
                arr.push_back(mp[arr[index]][1]);
            }
            index++;

        }

        return arr;
    }
};