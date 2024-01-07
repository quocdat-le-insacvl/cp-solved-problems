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
	int k, g, m;
	cin >> k >> g >> m;
	int ng=0, nm=0;
	for (int i=0; i<k; i++) {
		if (ng == g) ng = 0;
		else if (nm == 0) {
			nm = m;
		}
		else {
			if (nm > g - ng) {
				nm -= g - ng;
				ng = g; 
			} else{
				ng += nm;
				nm = 0;
			}
		}
		cout << ng << ' ' << nm << '\n';
	}
	cout << ng << ' ' << nm << '\n';
  return 0;
}
