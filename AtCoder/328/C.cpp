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
	int N, Q; cin >> N >> Q;
	string S; cin >> S;
	vector<int> A(N);
	for (int i=1; i<N; i++) {
		if (S[i] == S[i-1]) {
			A[i] = A[i-1] + 1;
		} else A[i] = A[i-1];
	}
	//dbg(A);
	while (Q--){
		int i,j; cin >> i >> j;
		cout << A[--j] - A[--i] << '\n';
	}

  return 0;
}
