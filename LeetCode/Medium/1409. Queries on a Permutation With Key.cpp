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

Question : 1409. Queries on a Permutation With Key
Topic : Array
Problems : https://leetcode.com/problems/queries-on-a-permutation-with-key/
*/

class Solution {
public:
    
    
    void replaceElementIntoArray(vi &arr,int index) {

        int replacedEle = arr[index];
        while(index > 0) {
            arr[index] = arr[index-1];
            index--;
        }
        arr[0] = replacedEle;
    }
    
    

    
    
    vector<int> processQueries(vector<int>& quries, int m) {
        int n = quries.size();
        vi ans(n,0);
        vi arr(m,0);
        for(int i = 0; i < m; i++) arr[i] = i + 1;


        for(int i = 0; i < n; i++) {
            for(int j = 0;j < m; j++) {
                if(quries[i] == arr[j]) {
                    replaceElementIntoArray(arr, j);
                    ans[i] = j;
                }
            }
        }


        // REP(i,n) cout << ans[i] << ' ';
        // cout << endl;

        return ans; 
    }
};

int main() {

	Solution ob;
    vi quries = {3,1,2,1};
    string res=  ob.processQueries(quries, 5);
    cout << res << endl;
}