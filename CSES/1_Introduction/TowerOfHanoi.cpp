#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/nightfury/mycp/debug.h"
#else
#define dbg(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
	int n; cin >> n;
	deque<int> l, m , r;
	for (int i=0; i<n; i++) {
		l.push_front(i);
	}
	unordered_set<string> dv;
	string s;
	for (auto x: l) {
		s += to_string(x);
	}

	// res + save string


	dbg(l);
  return 0;
}
