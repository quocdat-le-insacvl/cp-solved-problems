#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/nightfury/mycp/debug.h"
#else
#define dbg(...) 42
#endif

vector<pair<int,int>> qq;
void pm(int s, int e){
	qq.push_back({s,e});
}

void pm_(int s, int e){
	cout << s << ' ' << e << '\n';
}

void hanoi(int n, int start, int end) {
	if (n == 1){
		pm(start,end);
	} else{
		int inter = 6-start-end;
		hanoi(n-1,start, inter);
		pm(start, end);
		hanoi(n-1, inter,end);
	}
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
	int n; cin >> n;
	hanoi(n, 1, 3);

	cout << size(qq) << '\n';
	for(auto [s,e]: qq){
		pm_(s,e);
	}

  return 0;
}
