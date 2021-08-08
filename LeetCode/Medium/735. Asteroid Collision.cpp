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

Question : 735. Asteroid Collision
Topic : Stack
Problems : https://leetcode.com/problems/asteroid-collision/


/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================

*/



class Solution {
public:
    
    // O(N) - O(N) using seperate stack
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;
        int i = 0;

        while(i < asteroids.size()) {

            if(asteroids[i] < 0) {
                if(st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                }
                else {
                    while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])) {
                        st.pop();
                    }
                    if(st.empty() || st.top() < 0) {
                        st.push(asteroids[i]);
                    }
                    else if(st.top() == abs(asteroids[i])) {
                        st.pop();
                    }
                }
            }
            else {
                st.push(asteroids[i]);
            }
        i++;
        }

        int size = st.size();
        vector<int> result(size,0);
        while(!st.empty()) {
            result[--size] = st.top();
            st.pop();
        }

        return result;
    }



    // O(N) - O(1) stack based solution
   vector<int> asteroidCollision(vector<int>& asteroids) {

        vector<int> result;
        int i = 0;

        while(i < asteroids.size()) {

            if(asteroids[i] < 0) {
                if(result.empty() || result.back() < 0) {
                    result.push_back(asteroids[i]);
                }
                else {
                    while(!result.empty() && result.back() > 0 && result.back() < abs(asteroids[i])) {
                        result.pop_back();
                    }
                    if(result.empty() || result.back() < 0) {
                        result.push_back(asteroids[i]);
                    }
                    else if(result.back() == abs(asteroids[i])) {
                        result.pop_back();
                    }
                }
            }
            else {
                result.push_back(asteroids[i]);
            }
            i++;
        }

        return result;
    }

};