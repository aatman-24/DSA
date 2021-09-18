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

Question: 1654. Minimum Jumps to Reach Home
Topic : BFS
Problems : https://leetcode.com/problems/minimum-jumps-to-reach-home/

==============================> Explanation <=============================================
- Perfrom the BFS.

Forward.
Backward. -> But can not perform two time in line. So keep track of where it came from
the current position.

for Each X Two possiblites, it is visited in forward and also it can be visited 
in backward reason is that, a and b are not same that's why. if a and b are
same then forward(visited) work.

1....15
a = 5, b = 2, x = 4(you understadn that in last step... backward(5) visit the backward(3)).

==============================> Apporach and Time Complexity <=============================================

1) BFS:
Time:  O(N^2)(Every Position Can be visited exactly two times)
Space: O(N)(Visited + Queue)
*/


class Solution {
public:
    
const int MAX_LIMIT = 10000;
    
int minimumJumps(vector<int>& forbidden, int a, int b, int target) {

    // prepare the set which can give O(1) lookup/search functionality.
    unordered_set<int> st(forbidden.begin(), forbidden.end());
    
    // Here Two state is possible, the node is visited from left -> right(forward direction)
    // And also right -> left(backward direction)
    // Can't mix both state into the one. Both are differnt.
    vector<int> backward_v(MAX_LIMIT, 0);
    vector<int> forward_v(MAX_LIMIT, 0);
    

    // Setup for BFS.
    queue<pair<int,bool>> q;
    q.push({0, false});
    backward_v[0] = forward_v[0] = true;

    int level = 0;
    while(!q.empty()) {
        
        int size = q.size();

        for(int j = 0; j < size; j++) {

            auto [x, backward] = q.front(); q.pop();
            
            if(x == target)
                return level;

            // forward
            if(x + a < MAX_LIMIT && !forward_v[x+a] && !st.count(x+a)) {
                forward_v[x+a] = 1;
                q.push({x+a, false});
            }
            

            // backward
            if(x - b >= 0 && !backward_v[x-b] && !backward && !st.count(x-b)) {
                backward_v[x-b] = 1;
                q.push({x-b, true});
            }
        }
        level++;
    }

    return -1;
}
};