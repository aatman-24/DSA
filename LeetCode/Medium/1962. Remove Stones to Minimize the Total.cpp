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

Question: 1962. Remove Stones to Minimize the Total
Topic : maxHeap
Problems : https://leetcode.com/problems/remove-stones-to-minimize-the-total/

==============================> Explanation <=============================================
- Given that once you take from the ith pile then also you can take from the ith pile second time.
- Works greedily take most of from the pile so that reason choose the maximum number of piles to remove the
piles.
- Just put into the maxHeap which give the maxNumber of stone. Take half of them from it and again push
remaining into the heap. Keeptrack of total stone remain at the end.



==============================> Apporach and Time Complexity <=============================================
1) maxHeap:
Time:O(klogN)
Space:O(K)

*/

class Solution {
public:

    int minStoneSum(vector<int>& piles, int k) {

        int count = 0;

        priority_queue<int, vector<int>> pq;
        
        for(int num: piles) {
            pq.push(num);
            count += num;        
        }

        for(int i = 0; i < k; i++) {
            int num = pq.top(); pq.pop();
            count -= floor(num / 2);
            num -= floor(num/2);
            pq.push(num);
        }

        return count;
    }
};