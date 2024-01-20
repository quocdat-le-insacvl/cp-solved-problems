#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/nightfury/mycp/debug.h"
#else
#define dbg(...) 42
#endif

vector<string> a(8);
int ans = 0;

void  BT(int qi, vector<int> picked) {
	if (qi == 8) {
		bool ok = true;
		for (int i=0; i<8; i++) {
			if (a[i][picked[i]] == '*'){
				ok = false;
				break;
			}
		}
		if (ok) ans++;
		return;
	}
	for (int i=0; i<8; i++) {
		bool ok = true;
		for (int j=0; j < picked.size(); j++ ) {
			if ((picked[j] == i) || (abs(qi-j) == abs(i - picked[j]))){
				ok = false;
				break;
			}
		}
		if (!ok) continue;

		vector<int> copie(picked);
		copie.push_back(i);
		BT(qi+1, copie);
	}
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
	int n = 8;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	BT(0,{});

	cout << ans << '\n';
  return 0;
}
