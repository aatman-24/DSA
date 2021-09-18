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

Question: 
Topic : 
Problems : 
==============================> Explanation <=============================================

==============================> Apporach and Time Complexity <=============================================

1) :
Time: 
Space: 

2) :
Time: 
Space: 

*/



class Solution {
    public:

    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> outdegree(n+1, 0);

        for(auto edge: trust) {
            outdegree[edge[0]]++;
        }

        int judge = -1;
        for(int i = 1; i <= n; i++) {
            if(outdegree[i] == 0) {
                if(judge >= 0)
                    return -1;
                judge = i;
            }
        }

        if(judge == -1)
            return -1;


        vector<int> visited(n+1, 0);
        for(auto edge: trust) {
            if(edge[1] == judge) 
                visited[edge[0]] = 1;
        }

        for(int i = 1; i <= n; i++) {
            if(visited[i] == 0 && i != judge)
                return -1;
        }


        return judge;
    }
    };


class Solution {
public:

    int findJudge(int n, vector<vector<int>>& trust) {

       vector<int> degree(n+1, 0);
       for(auto edge: trust) {
            degree[edge[0]]--;
            degree[edge[1]]++;
       }

       for(int i = 1; i <= n; i++) {
            if(degree[i] == n - 1)
                return i;
       }

       return -1;
    }
};#include <bits/stdc++.h>
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

Question: 997. Find the Town Judge
Topic : Graph, Indegree, Outdegree
Problems : https://leetcode.com/problems/find-the-town-judge/
==============================> Explanation <=============================================
1) Count outdegree of all the nodes. Whose Outdegree is zero it means this node
cannot trust on anyone and it should be one not more than one.
- After check all the nodes must trust on that node using visited array.


2) Same logic but with some extra, we count degree of each node. 
For Indegree it is going to be +, Outdegree it should be decrease,
Then for the judge indegree-outdegree=N-1(All other except itself).


==============================> Apporach and Time Complexity <=============================================

N = Number of Edges.
M = Number of nodes.
1) Mutliple Pass:
Time: O(Max(N, M))
Space: O(M)

2) One Pass:
Time: O(Max(N, M)))
Space: O(M)

*/



class Solution {
    public:

    int findJudge(int n, vector<vector<int>>& trust) {

        // count outdegree
        vector<int> outdegree(n+1, 0);
        for(auto edge: trust) {
            outdegree[edge[0]]++;
        }

        int judge = -1;
        for(int i = 1; i <= n; i++) {
            if(outdegree[i] == 0) {

                // two judge. which is not possible.
                if(judge >= 0)
                    return -1;
                judge = i;
            }
        }

        // NO judge found.
        if(judge == -1)
            return -1;


        // check that except judge, all nodes direct trust on judge or not.
        vector<int> visited(n+1, 0);
        for(auto edge: trust) {
            if(edge[1] == judge) 
                visited[edge[0]] = 1;
        }


        for(int i = 1; i <= n; i++) {

            // If there are node which is not judge and not trust on judge then no judge found.
            if(visited[i] == 0 && i != judge)
                return -1;
        }

        // Return Judge.
        return judge;
    }
    };


class Solution {
public:

    int findJudge(int n, vector<vector<int>>& trust) {

       vector<int> degree(n+1, 0);
       for(auto edge: trust) {
            degree[edge[0]]--;
            degree[edge[1]]++;
       }

       // whose indegree-outdegree=n-1 it is judge.
       for(int i = 1; i <= n; i++) {
            if(degree[i] == n - 1)
                return i;
       }

       return -1;
    }
};