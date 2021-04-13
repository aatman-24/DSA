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

Question : 950. Reveal Cards In Increasing Order
Topic : Queue, Array
Problems : https://leetcode.com/problems/reveal-cards-in-increasing-order/submissions/
*/


// Time Complexity  ((M+N) * M*N*log(min(M,N))))
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vi ans(n,0);
        
        queue<int> q;
        for(int i = 0;i < n; i++) q.push(i);

        sort(deck.begin(), deck.end());

        int i = 0;
        while(!q.empty()) {
            ans[q.front()] = deck[i];
            i++; q.pop();
            if(q.empty()) break;
            q.push(q.front());
            q.pop();
        }

        return ans;
    }
};
