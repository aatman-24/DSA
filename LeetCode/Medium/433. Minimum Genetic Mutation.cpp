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

Question: 433. Minimum Genetic Mutation
Topic : DFS, BFS, Brute-Force
Problems : https://leetcode.com/problems/minimum-genetic-mutation/

==============================> Explanation <=============================================
- Try every four character at each index and check wheather it is in bank or not if yes then 
we keep calling dfs(add into the queue in bfs). Until we reach at the target and check how many
stages required to reach at target we select the minimum.


==============================> Apporach and Time Complexity <=============================================

1) DFS + Brute-Force:
Time: O(8^4) * log(8^4) (NOT SURE)
Space: O(8^4)(map, visited, aux)

2) BFS + Brute-Force:
Time: O(8^4) * log(8^4) (NOT SURE)
Space: O(8^4)(map, visited, queue)

*/
class Solution {
public:
    
    int ans = INT_MAX;

    char characters[4] = {'A', 'C', 'G', 'T'};

    void dfs(string src, string target, map<string,string> &bank, map<string,string> &visited, int changed) {

        
        if(src == target) {
            ans = min(ans, changed);
            return;
        }

        visited[src] = src;


        for(int j = 0; j < 8; j++) {

             for(int i = 0; i < 4; i++){
                 
                
                string nw_string = src;
                
                nw_string[j] = characters[i];
                
                
                if(bank.count(nw_string) && !visited.count(nw_string)){
                    dfs(nw_string, target, bank, visited, changed+1);
                }

            }
        }  
    }


    int minMutation(string start, string end, vector<string>& bank) {
        
        map<string, string> mp, visited;

        for(string gene: bank) {
            mp[gene] = gene;
        }

        if(mp.find(end) == mp.end())
            return -1;

        dfs(start, end, mp, visited, 0);

        return ans == INT_MAX ? -1 : ans;
    }


};



    

class Solution {
public:
    

    char characters[4] = {'A', 'C', 'G', 'T'};

    int bfs(string src, string target, map<string,string> &bank, map<string,string> &visited) {
        
        queue<string> q;
        q.push(src);
        visited[src] = src;

        int level = 0;

        while(!q.empty()) {
            
            int size = q.size();
            for(int k = 0; k < size; k++) {

                string temp =  q.front(); q.pop();

                if(temp == target)
                    return level;

                for(int j = 0; j < 8; j++) {

                    for(int i = 0; i < 4; i++) {

                        string nw_string = temp;
                        nw_string[j] = characters[i];

                        if(bank.count(nw_string) && !visited.count(nw_string)) {
                            visited[nw_string] = nw_string;
                            q.push(nw_string);
                        }

                    }
                }
            }
            level++;
        }

        return -1;
    }


    int minMutation(string start, string end, vector<string>& bank) {
        
        map<string, string> mp, visited;

        for(string gene: bank) {
            mp[gene] = gene;
        }

        if(mp.find(end) == mp.end())
            return -1;

        int ans = bfs(start, end, mp, visited);

        return ans;
    }

};
