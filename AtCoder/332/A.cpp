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
	int n, s, k; 
	cin >> n >> s >> k;
	int ans = 0;
	for (int i=0; i<n; i++) {
		int a, b ;
		cin >> a >> b;
		ans += a * b;
	}
	if (ans < s) ans += k;
	cout << ans << '\n';
  return 0;
}
