#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/nightfury/mycp/debug.h"
#else
#define dbg(...) 42
#endif

long long ans = 1e12;
vector<int> a;
long long sum_a;

void BT(int i, long long sum){
	dbg(i);
	if (i >= a.size()) {
		ans = min(ans, abs(sum_a - 2*sum));
		return;
	}
	// cout << i << '\n';
	BT(i+1, sum + a[i]);
	BT(i+1, sum);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
	int n; cin >> n;
	a.resize(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
		sum_a += a[i];
	}
	dbg(a);
	BT(0, 0);


	cout << ans << '\n';
  return 0;
}
