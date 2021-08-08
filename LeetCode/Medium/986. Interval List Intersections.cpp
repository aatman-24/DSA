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

Question : 986. Interval List Intersections
Topic : Two pointer 
Problems : https://leetcode.com/problems/partition-labels/
*/


class Solution {
public:

    // O(N) - O(1)
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    int n = firstList.size(), m = secondList.size();
    vector<vector<int>> res;
    vector<int> tmp;
    int i = 0, j = 0;
    while(i < n && j  < m) {
        tmp.clear();
        if(firstList[i][1] <= secondList[j][1]) {
            if(firstList[i][0] >= secondList[j][0]) {
                tmp = {firstList[i][0], firstList[i][1]};
                res.push_back(tmp);
            }
            else if(secondList[j][0] <= firstList[i][1]){
                tmp = {secondList[j][0], firstList[i][1]};
                res.push_back(tmp);
            }
            i++;
        }
        else if (secondList[j][1] <= firstList[i][1]) {
            if(secondList[j][0] >= firstList[i][0]) {
                tmp = {secondList[j][0], secondList[j][1]};
                res.push_back(tmp);
            }
            else if (firstList[i][0] <= secondList[j][1]) {
                tmp = {firstList[i][0], secondList[j][1]};
                res.push_back(tmp);
            }
            j++;
        }
    }
    return res;
    }
};