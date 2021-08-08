#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;

using namespace std;


typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef map<int,int> mii;

/* ==============================> Description <=============================================
Question : 1431. Kids With the Greatest Number of Candies
Topic : Array, greedy
Problems : https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
*/


class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int maxCandie = *max_element(candies.begin(), candies.end());
    
        int n = candies.size();
        
        vector<bool> res;
        for(int i = 0; i < n; i++) {
            if(candies[i] + extraCandies >= maxCandie) res.push_back(true);
            else res.push_back(false);
        }

        return res;
    }
};


int main() {

	Solution obj;


	vi arr = {4,2,1,1,2};
	vector<bool> res = obj.kidsWithCandies(arr, 1);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	
}

