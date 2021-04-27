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


// https://github.com/williamfiset/Algorithms/blob/master/src/main/java/com/williamfiset/algorithms/graphtheory/TspDynamicProgrammingRecursive.java
// https://github.com/williamfiset/Algorithms/blob/master/src/main/java/com/williamfiset/algorithms/graphtheory/TspDynamicProgrammingIterative.java


/*
==============================> Description <=============================================

Question : TSP STANDARD
Topic : 
Problems :
*/

int N;
int dist[N][N], memo[N][1 << N], prev[N][1<<N];

int tsp(int pos, int bitmask) {

	if(bitmask == (1 << (N+1)) - 1) {
		return dist[pos][0]; // from the last to start pos. here start position = 0.
	}

	if(memo[pos][bitmask] != -1) return memo[pos][bitmask];


	int minCost = INT_MAX;
	int index = -1;

	for(int nxt = 0; nxt < N; nxt++) {
		if(nxt != pos && !(bitmask & (1 << nxt))) {  // if the node is node visited 
			int nextState = bitmask | (1 << nxt); // we set the nxt bit into bitmask using or.
			int newCost = dist[pos][nxt] + tsp(nxt, nextState);   
			if(newCost < minCost) {
				minCost = newCost;
				index = next;
			}
		}
	}

	prev[i][bitmask] = index;
	return memo[pos][bitmask] = minCost;
}


int getCost(int start) {
	int state = 1 << start;
	return tsp(start, state);
}

vi getTour(int start) {
	int state = 1 << start;
	int minCost = tsp(start, state);

	// Regenerate path
	vi tour;
    int index = start;

    while (true) {
      tour.push_back(index);
      int nextIndex = prev[index][state];
      if (nextIndex == -1) break;
      int nextState = state | (1 << nextIndex);
      state = nextState;
      index = nextIndex;
    }

    tour.push_back(start);
    return tour;
}

void main() {
	memset(memo, -1, sizeof(memo));
	memset(prev, -1, sizeof(prev));
	getCost(start);
	getTour(start);
}

