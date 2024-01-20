#include <iostream>
#include <vector>

#ifdef LOCAL
#include "/home/nightfury/mycp/debug.h"
#else
#define dbg(...) 42
#endif

using std::vector;

// The graph represented as an adjacency list (0-indexed)
vector<vector<int>> neighbors{{1, 2}, {0}, {0, 3, 4}, {2}, {2}};
vector<int> start(neighbors.size());
vector<int> end_(neighbors.size());
int timer = 0;

void euler_tour(int at, int prev) {
	start[at] = timer++;
	for (int n : neighbors[at]) {
		cout << n << '\n';
		if (n != prev) { euler_tour(n, at); }
	}
	end_[at] = timer;
}

int main(){
	euler_tour(0, 0);
	dbg(start);
	dbg(end_);
	return 0;
}
