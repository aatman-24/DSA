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

Question: 451. Sort Characters By Frequency
Topic : Heap, bucket sort
Problems : https://leetcode.com/problems/sort-characters-by-frequency/

==============================> Explanation <=============================================

Parent Question: 347. Top K Frequent Elements

1) count the frequency using map then put into the heap which max size is upto 256 which is fixed.
So it will take O(NlogK) where k = 256 which is constant so it will be O(N).

2) Bucket sort. Count the frequency first then create the [n+1] bucket and add all the
element into that bucket. bucket[i] -> j means j element has i frequency.
- After that, we start visiting the bucket in decreasing order that is the main reason
we use bucket sort.

Follow Up Question,
Here the same freq character order is not matter but if given that if freq is same
then print it in lexigraphically that time use sort_fun to sort it first. That time
sort the bucket array first. Which take O(NlogK) -> k = 256 constant so it is O(N).

==============================> Apporach and Time Complexity <=============================================
K = 256, (couting purpose)

1) Brute Force:
Time: O(N^2)
Space: O(K)

2) Sorting:
Time: O(NlogN)
Space: O(K)

2) Heap:
Time: O(NlogK) -> K constant -> O(N)
Space: O(K)

4) Bucket:
Time: O(N) 
Space: O(N)


*/


class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> count;
        for(auto ch: s) {
            count[ch]++;
        }

        priority_queue<pair<int,char>, vector<pair<int,char>>> pq;
        for(auto [ch, freq] : count) {

            // We are adding the pair based on freq, but still in pq contain the maximum
            // 256 elements reason is that freq might be differnt but ch is upto 256.
            // So there is no chance it is going above 256.
            pq.push({freq, ch});
        }


        vector<char> ans(s.size());
        int k = 0;
        while(!pq.empty()) {
            auto [freq, ch] = pq.top(); pq.pop();
            for(int i = 0; i < freq; i++) {
              ans[k++] = ch;
            }
        }

        string res;
        for(auto ch: ans) {
            res += ch;
        }
        
        return res;
    }
};



class Solution {
public:

    string frequencySort(string s) {

        unordered_map<char,int> count;
        for(auto ch: s) {
            count[ch]++;
        }

        vector<char> bucket[s.size() + 1];
        for(auto [ch, freq] : count) {
            bucket[freq].push_back(ch);
        }
        
        // for optimization. Adding to the string take O(N^2) times.
        vector<char> ans(s.size());
        int k = 0;
    
        for(int i = s.size(); i > 0; i--) {
            if(bucket[i].size() > 0) {
                for(auto ch: bucket[i]) {
                    for(int j = 0; j < i; j++)
                        ans[k++] = ch;
                }
            }
        }

        string res;
        for(auto ch: ans) {
            res += ch;
        }
        
        return res;
    }
};