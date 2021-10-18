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

Question: 923. 3Sum With Multiplicity
Topic : Hashing, ThreeSum, Combination
Problems :https://leetcode.com/problems/3sum-with-multiplicity/

==============================> Explanation <=============================================
1) Three sum Using Map: Same apporach is used... using two loop make (nums[i] + nums[j]) and check 
target - (nums[i] + nums[j]) is in the map or not. And in map we store the <num,freq>.

2) Second apporach is combination approach:
- In which we first make entry into map. Then we count the total combination. 
- Two Loop on Freq, Got i and j from here,
    k = target - (i + j)
    check k is in the map or not.
    
    case 1: i < j < k.... means all are at different then, res += freq[i] * freq[j] * freq[k]

    case 2: i == j && j != k... means two of them are same.  res += (freq[i] * (freq[i]-1)) / 2! * freq[k]

    case 3: i == j && j == k... means all are same number... res += (freq[i] * (freq[i]-1) * (freq[i]-2)) / 3



==============================> Apporach and Time Complexity <=============================================
N = 100.

1) Three sum:
Time: O(N^2)
Space: O(N)

2) Combination:
Time:O(N^2)
Space:O(N)
*/


class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {

        unordered_map<long,long> mp;
        long res = 0;

        for(int i = 1; i < arr.size()-1; i++) {

            mp[arr[i-1]]++;

            for(int j = i + 1; j < arr.size(); j++) {

                int want = target - arr[i] - arr[j];

                if(mp.count(want)) {
                    res = (res + mp[want] % mod) % mod;
                }
            }
        }

        return res;
    }
};



#define mod 1000000007

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {

        unordered_map<int,long> freq;
        
        for(int num: arr)
            freq[num]++;
        
        long res = 0;

        for(auto num1: freq) {

            for(auto num2: freq) {

                int i = num1.first, j = num2.first;

                int k = target - i - j;

                if(!freq.count(k))
                    continue;

                if(i < j && j < k) {
                    long combination = freq[i] * freq[j] * freq[k];
                    res = (res + combination % mod) % mod; 
                }
                else if(i == j && j != k) {
                    long combination = freq[i] * (freq[i]-1) * freq[k] / 2;
                    res = (res + combination % mod) % mod;
                }
                else if(i == j && j == k) {
                    long combination = freq[i] * (freq[i]-1) * (freq[i]-2) / 6;
                    res = (res + combination % mod) % mod;
                }
            }
        }

        return res;
    }
};