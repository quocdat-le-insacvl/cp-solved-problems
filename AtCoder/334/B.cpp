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
	long long a, m, l, r;
	// l <= a + mk <= r
	// l - a <= mk <= r - a
	// (l-a) / m <= k <= (r-a) / m
	
	cin >> a >> m >> l >> r;
	long long ll = ceil((l-a) / m);
	long long rr = floor((r-a) / m);
	cout << ll << rr << '\n';

	cout << max((long long)0, rr - ll) << '\n';

  return 0;
}
