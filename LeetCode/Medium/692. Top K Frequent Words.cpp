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

Question: 692. Top K Frequent Words
Topic : Heap, bucket sort
Problems : https://leetcode.com/problems/top-k-frequent-words/

==============================> Explanation <=============================================

Parent Question: 347. Top K Frequent Elements

1) Count the Frequency and then create new array pair<count, string> sort it and take the
top k elements from it. O(NlogN)(Worst Case while all words are differnt).

2) Max Heap: Add all the <freq, word> into the heap. Which take O(NLogN) time. AFter
pop the K element from it O(logK).

3) Min Heap: Use Min Heap and maintain the size if pq.size() > k then pop the element.
O(NlogK). 
Note, If you make the comparator for minHeap then it should be work like maxHeap remember it.

4) Bucket sort. Count the frequency first then create the [n+1] bucket and add all the
element into that bucket. bucket[i] -> j means j element has i frequency. 
- After that, we start visiting the bucket in decreasing order that is the main reason
we use bucket sort. Here elements in bucket should be in lexo order so sort it.


==============================> Apporach and Time Complexity <=============================================
M = Longest string length.

1) Brute Force:
Time: O(M*NLogN)
Space: O(N)

2) MaxHeap:
Time: O(M*NlogN) + O(logK)
Space: O(N)


3) Min Heap:
Time: O(M*NlogK)
Space: O(N)

4) Bucket:
Time: O(N*Z*logK) -> Z longest bucket size. 
Space: O(N)


*/


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        // count frequency.
        unordered_map<string, int> count;
        for(string word: words) {
            count[word]++;
        }

        // add into the bucket.
        vector<string> bucket[words.size() + 1];
        for(auto [word, freq]: count) {
            bucket[freq].push_back(word);
        }

        vector<string> answer(k);
        int index = 0;
        for(int i = words.size(); i > 0; i--) {
            if(bucket[i].size() > 0) {

                // sort the bucket in lexogrphically.
                sort(bucket[i].begin(), bucket[i].end());
                for(auto word: bucket[i]) {
                    answer[index++] = word;
                    if(index == k)
                        return answer;
                }
            }
        }

        return answer;
    }
};






class CompareClass {
public:
    bool operator() (pair<int,string> &p1, pair<int,string> &p2) {
        if(p1.first == p2.first) return p1.second < p2.second;
        return p1.first > p2.first;
    }
};
    


class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {

        // frequncy count.
        unordered_map<string, int> count;
        for(string word: words) {
            count[word]++;
        }

        // pq with compartor.
        priority_queue<pair<int,string>, vector<pair<int,string>>, CompareClass> pq; 

        for(auto [word, freq]: count) {
            pq.push({freq, word});
            if(pq.size() > k) {
                pq.pop();
            }
        }


        vector<string> answer(k);
        while(!pq.empty()) {
            auto [freq, word] = pq.top(); pq.pop();
            answer[--k] = word;
        }


        return answer;
    }
};
