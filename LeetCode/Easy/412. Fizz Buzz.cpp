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

Question : 412. Fizz Buzz
Topic : Number Therory
Problems : https://leetcode.com/problems/fizz-buzz/

==============================> Explanation <=============================================

- :)

==============================> Apporach and Time Complexity <=============================================

1) Number Therory
Time: O(N)
Space: O(1)

*/


class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for(int i = 1; i <= n; i++) {
            if(i % 3 == 0 && i % 5 == 0) {
                answer.push_back("FizzBuzz");
            }
            else if(i % 3 == 0) {
                answer.push_back("Fizz");
            }
            else if(i % 5 == 0) {
                answer.push_back("Buzz");
            }
            else {
                answer.push_back(to_string(i));
            }
        }
    }
    return answer;
};



