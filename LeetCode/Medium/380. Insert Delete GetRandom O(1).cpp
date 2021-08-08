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

Question : 380. Insert Delete GetRandom O(1)
Topic : Set
Problems : https://leetcode.com/problems/insert-delete-getrandom-o1/
/*
==============================> Explanation <=============================================

used map to store the index of val.

how to remove in O(1).
- find the last element in the array and it index from map.
- change the index of it into map with current element index.
- into array also currnet element swap with last element of array.
- remove from both map and vector(last element).

*/

/*
==============================> Edge Case <=============================================


*/

class RandomizedSet {
private:
    vector<int> arr;
    unordered_map<int,int> mp;


public:

    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        arr.push_back(val);
        mp[val] = arr.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        int last = arr.back();
        mp[last] = mp[val];
        arr[mp[last]] = last;
        arr.pop_back();
        mp.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */