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
	for (int i=0; i<n; i++) {
		long long k; cin >> k;
		long long j=1;
		long long p=1;
		while (k > j*p*9) {
			k-=j*p*9;
			p*=10;
			j++;
		}
		long long s = p - 1 + (long long)(k/j);
		if (k % j == 0) {
			string ss = to_string(s);
			cout << ss[ss.size()-1] << '\n';
		} else {
			string ss = to_string(s + 1);
			cout << ss[k%j-1] << '\n';
			
		}
	}
  return 0;
}
