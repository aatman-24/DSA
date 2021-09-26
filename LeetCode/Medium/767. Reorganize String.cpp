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

Question: 767. Reorganize String
Topic : maxHeap, Couting, Odd-Even Placing
Problems : https://leetcode.com/problems/reorganize-string/

==============================> Explanation <=============================================

Parent: 1054. Distant Barcodes

But When the Such string is not possible?

s -> 5
most_frquent -> 3 (Valid).

0 1 2 3 4 
a   a   a

But if most_frquent -> 4(Invalid).

So answer is, most_frquent > (n+1)/2 -> Become Invalid. (More than half element is same
not possible to place near to each other).



- Ideas is clear that, Here already given that arranging element that way is possible
then we directly think about greedy approach.

1) We arrange most frequent element first by placing +2 index. So for that we count
frequency and put into maxHeap.
- Next step pop out the element which have  max frequency in pq and arrange that element
from the last (i). If we hint the i at the boundary (i >= n) then we start from 
the i = 1 index. 
- This can be done in two pass. Because 0 -> 2(index) already filled, 1 -> 3(index)
already filled so we just need to start from the index = 0, index = 1.
- but using pq can make O(NlogN).

2) Second approach is not using pq.
- We used map to count frequency. But here our ideas is to place the most frequent
element into the even index(0, 2, 4....n) first and after no matter which element is next,
we start filling the index where most frequent stop... so doing that it will guarantee us
(0, 2, 4.... n) is already filled so no same element can be placed in besides of each othere.
- so other element can be placed at any blank index.

==============================> Apporach and Time Complexity <=============================================
Here, we assume that adding into string take O(1). Otherwise it make O(N^2) all algorithm
which is not inplace.

1) MaxHeap:
Time: O(NLogN)
Space: O(N)

2) Odd-Even Placing:
Time: O(N)
Space: O(N)

2) Odd-Even Placing + Inplace:
Time: O(N)
Space: O(1)


*/

class Solution {
public:

    vector<int> rearrangeBarcodes(vector<int>& barcodes) {

        int n = barcodes.size();

        unordered_map<int,int> count;
        for(auto it: barcodes) {
            count[it]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        for(auto it: count) {
            pq.push({it.second, it.first});
        }

        vector<int> arr(n, 0);
        int i = 0;
        while(!pq.empty()) {

            auto it = pq.top(); pq.pop();
            int num = it.second, freq = it.first;
            
            while(freq > 0) {
                arr[i] = num;
                freq--;
                i = i + 2 < n ? i + 2: 1;
            }
        }

        return arr;
    }
};



class Solution {
public:

    string reorganizeString(string s) {

        
        int n = s.size();
        
        unordered_map<char,int> count;
        int max_count=0;
        char max_char;
        for(auto it: s) {
            count[it]++;
            if(count[it] > max_count){
                max_count = count[it];
                max_char = it;
            }
        }

        if(max_count > (n+1)/2) return "";

        vector<char> ans(n, 0);
        
        // placed most frquent first.
        int i = 0;
        while(max_count) {
            ans[i] = max_char;
            max_count--;
            i = i + 2 < n ? i + 2 : 1; 
        }

        for(auto it: count) {

            char ch = it.first;
            int freq = it.second;

            if(ch == max_char)
                continue;
        
            while(freq) {
                ans[i] = ch;
                freq--;
                i = i + 2 < n ? i + 2 : 1;
            } 
        }

        string ans_s;
        for(int i = 0; i < n; i++) {
            ans_s += ans[i];
        }


        return ans_s;
    }   
};


class Solution {
public:

    string reorganizeString(string s) {

        
        int n = s.size();
        
        unordered_map<char,int> count;
        int max_count=0;
        char max_char;
        for(auto it: s) {
            count[it]++;
            if(count[it] > max_count){
                max_count = count[it];
                max_char = it;
            }
        }

        if(max_count > (n+1)/2) return "";

        // placed most frequent first.
        int i = 0;
        while(max_count) {
            s[i] = max_char;
            max_count--;
            i = i + 2 < n ? i + 2 : 1; 
        }

        for(auto it: count) {

            char ch = it.first;
            int freq = it.second;

            if(ch == max_char)
                continue;
        
            while(freq) {
                s[i] = ch;
                freq--;
                i = i + 2 < n ? i + 2 : 1;
            } 
        }

        return s;
    }   
};