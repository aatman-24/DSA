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

Question: 204. Count Primes
Topic : Prime, Sieve
Problems : https://leetcode.com/problems/count-primes/

==============================> Explanation <=============================================
1) Check Every Number upto the N, isPrime() or not. 

2) Sieve Algorithm. 

==============================> Apporach and Time Complexity <=============================================

1) Brute Force:
Time: O(N * SQRT(N)) (TLE Here, N = 10^6)
Space: O(1)

2) Seive:
Time: O(N log N) (Actual O(N log log N)).
Space: O(N)

*/

class Solution {
public:
    bool isPrime(int n) {

        for(int i = 2; i <= sqrt(n); i++) {
            
            if(n % i == 0)
                return false;
        }
        
        return true;
    }

    int countPrimes(int n) {

        if(n <= 1) 
            return 0;
        
        int count = 0;
        for(int i = 2; i < n; i++) {
            if(isPrime(i)) {
                count++;
            }
        }   
        return count;
    }     
};



class Solution {
public:
    
    int countPrimes(int n) {

        vector<bool> prime(n, true);
        int count = 0;

        int _sieve_size = n;
 
        for(int i = 2; i < _sieve_size; i++) {

            if(prime[i]) {
                
                // logN time.
                for(int j = i; j < _sieve_size; j += i) {
                    prime[j] = false;
                }

                count++;
            }
        } 
      
        return count;
    }
};