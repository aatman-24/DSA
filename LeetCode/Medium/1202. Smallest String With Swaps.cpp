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

Question: 1202. Smallest String With Swaps
Topic : union-find
Problems : https://leetcode.com/problems/smallest-string-with-swaps/


==============================> Explanation <=============================================
Idea is clear that,

- All the indices in the same component all can be sorted based on string char. So we use the
same Idea.

- Given pair we used as union(u, v) and found the parent of all elements.
- Then we check every indices parent and put into that component. 
- Make string for each componenet and sort them.
- And again replace into the original string. That's how it works.

Now If we don't use Optimization of union-find it will return TLE. Because s.size() <= 10^5.
So we must use rank[] and parent optimization both to avoid TLE.


==============================> Apporach and Time Complexity <=============================================

1) Union-Find:
Time: O(N*logN)(For every component we sort the string) + O(4*alpha*N)(Union-find)
Space: O(N)

*/


class Solution {
public:
    
    int parent[100001];
    int rank[100001];

    void make_set(int n) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findParent(int u) {
        if(parent[u] == u)
            return u;
        return parent[u] = findParent(parent[u]);
    }



    void union_(int u, int v) {
       
       u = findParent(u);
       v = findParent(v);

       if(rank[u] < rank[v]) {
            parent[u] = v;
       }
       else if(rank[v] < rank[u]) {
            parent[v] = u;
       }
       else {
            parent[v] = u;
            rank[u]++;
       }
    }


    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {

        int n = s.size();

        vector<int> components[n];

        make_set(n);

        for(auto edge: pairs) {
            union_(edge[0], edge[1]);
        }

        for(int i = 0; i < n; i++) {
            components[findParent(i)].push_back(i);
        }

        for(auto comp: components) {
            
            string ss;
            for(auto it: comp) {
                ss += s[it];
            }
            
            sort(ss.begin(), ss.end());
            
            for(int i = 0; i < comp.size(); i++) {
                s[comp[i]] = ss[i];
            }
        }

        return s;
    }
};