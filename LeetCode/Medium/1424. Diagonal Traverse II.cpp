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

Question: 1424. Diagonal Traverse II
Topic : minHeap, Hashing
Problems : https://leetcode.com/problems/diagonal-traverse-ii/

==============================> Explanation <=============================================
- Ideas from the N-Queen Branch and Bound concept,

In matrix (i + j) is same then it represent the (leftBottom-rightTop) diagonal. Same 
Cocept is used.


1) Add all the elements in pq and pop all elements and add that on answer.
Compare class,
We need minHeap. (i+j) is less but i(row) is greater if (i+j) is same then.

2) Map +( Stack | Reverse vector): Add the elements in the (i+j) keys stack. Order is
matter so please do it with pen and paper.

==============================> Apporach and Time Complexity <=============================================
N = Total Elements.

1) Priority Queue:
Time: O(N*logN)
Space: O(N)

3) Map + Stack:
Time:O(N*logK) (K is max (i + j)).
Space:O(N)

*/


class compare {
public:
    bool operator() (vector<int> &v1, vector<int> &v2) {

        // (i+j) is less but i(row) is greater if (i+j) is same then.
        // perform in reverse.

        if(v1[0] == v2[0]) return v1[1] < v2[1]; // i is less
        return v1[0] > v2[0]; // (i + j) is great.
    }
};


class Solution {
public:

vector<int> findDiagonalOrder(vector<vector<int>>& nums) {

    priority_queue<vector<int>, vector<vector<int>>, compare> pq;
    int size = 0;

    for(int i = 0; i < nums.size(); i++) {
        for(int j = 0; j < nums[i].size(); j++) {
            pq.push({i+j, i, nums[i][j]});
            size++;
        }
    }

    vector<int> ans(size, 0);
    int i = 0;
    while(!pq.empty()) {
        auto it = pq.top();
        ans[i++] = it[2]; pq.pop();
    }

    return ans;
}
};



class Solution {
public:

    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {

        map<int,vector<int>> mp;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums[i].size(); j++) {
                mp[i+j].push_back(nums[i][j]);
            }
        }


        vector<int> ans;
        for(auto it: mp) {
            vector<int> tmp = it.second;
            for(int i = tmp.size()-1; i >= 0; i--) {
                ans.push_back(tmp[i]);
            }
        }

        return ans;
    }
};


class Solution {
public:

    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {

        map<int,stack<int>> mp;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums[i].size(); j++) {
                mp[i+j].push(nums[i][j]);
            }
        }


        vector<int> ans;
        for(auto it: mp) {
            stack<int> tmp = it.second;
            while(!tmp.empty()) {
                ans.push_back(tmp.top());
                tmp.pop();
            }
        }

        return ans;
    }
};



