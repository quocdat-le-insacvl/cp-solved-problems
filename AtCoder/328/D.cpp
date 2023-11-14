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
	string s; cin >> s;
	deque<char> qq;
	for (int i = 0; i < size(s); i++) {
		char c = s[i];
		if (c != 'C') qq.push_back(c);
		else{
			int n = size(qq);
			if (n >= 2 && qq[n-1] == 'B' && qq[n-2] == 'A') {
				qq.pop_back();
				qq.pop_back();
			} else {
				qq.push_back(c);
			}
		}
	}
	for (auto x: qq) {
		cout << x;
	}
	cout << '\n';
  return 0;
}
