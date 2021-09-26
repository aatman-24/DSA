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

Question: 1405. Longest Happy String
Topic : maxHeap, Sorting, Greedy
Problems : https://leetcode.com/problems/longest-happy-string/

==============================> Explanation <=============================================
- All Algorithm are same,

Ideas is that,

If a >= b >= c then, (b > 0)

In greedy Apporach, 

case 1: (b != 0), we use_a = min(2, use_a), a -= use_a, 
        we check (a >= b):
            ans += b, b--; (add B because in next round still "aa" is going to add)
        else:
            we don't add B. (Because if we add then in next step it become BBB).

TC: a->3 b->3,   aa(a->1, b->3) -> aab(a->1, b->2)
    b->2,a->1    aabbb(b->0, a->1) (Which is wrong). 
    That's why we don't add b. Because It will add two('BB') in next step.


case 2: (b == 0), then we just add the a -> use_a = min(2, use_a) times and return the
                  answer directly.
        (b == 0 && c == 0) because b > 0 so c is also zero already.
    
==============================> Apporach and Time Complexity <=============================================
1) Iteration:
Time: O(N*3log3)
Space: O(1)

3) Recurison and maxHeap:
Time:O(N*3log3)
Space:O(N)(Aux)

*/


class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        vector<pair<int,char>> arr = {{a, 'a'}, {b, 'b'}, {c, 'c'}};

        string ans="";

        while(true) {
            
            sort(arr.begin(), arr.end(), greater<pair<int,char>>());

            int used = min(2, arr[0].first);

            arr[0].first -= used;
                        
            if(used == 1)
                ans = ans + arr[0].second;

            if(used == 2)
                ans = ans + arr[0].second + arr[0].second;

            // Using only one char sequence of(2-1, 2-2) can not be created/
            if(arr[1].first == 0 && arr[2].first == 0)
                break;
            
            if(arr[0].first >= arr[1].first && arr[1].first > 0) {
                ans = ans + arr[1].second;
                arr[1].first--;
            }
            
                    
        }

        return ans;
    }
};



class Solution {
public:
        string longestDiverseString(int a, int b, int c) {

        priority_queue<pair<int,char>, vector<pair<int,char>>> pq;  

        if(a)
            pq.push({a, 'a'});

        if(b)
            pq.push({b, 'b'});

        if(c)
            pq.push({c, 'c'});
        

        string ans="";

        while(!pq.empty()) {
            
            auto [frqA, chA] = pq.top(); pq.pop();

            int used = min(2, frqA);
            frqA -= used;

            for(int i = 0; i < used; i++) {
                ans += chA;
            }

            // If it is not empty then we can still make the sequence of (2-1, 2-2)
            if(!pq.empty()) {

                auto [frqB, chB] = pq.top(); pq.pop();

                // If It holds then and only we add one B otherwise not.
                if(frqA >= frqB) {
                    ans += chB;
                    frqB--;
                }

                if(frqB)
                    pq.push({frqB, chB});
            }
            else {
                break;
            }

            if(frqA)
                pq.push({frqA, chA});
                    
        }

        return ans;
    }
};


class Solution {
public:
    string longestDiverseString(int a, int b, int c, char aa = 'a', char bb = 'b', char cc = 'c') {
        if (a < b)
            return longestDiverseString(b, a, c, bb, aa, cc);
        if (b < c)
            return longestDiverseString(a, c, b, aa, cc, bb);
        if (b == 0)
            return string(min(2, a), aa);

        // sorting a >= b >= c.

        
        // use_b is edge case.
        auto use_a = min(2, a), use_b = a - use_a >= b ? 1 : 0; 


        return string(use_a, aa) +  string(use_b, bb) + 
            longestDiverseString(a - use_a, b - use_b, c, aa, bb, cc);
    }
};