#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/nightfury/mycp/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
	int N; cin >> N;
	vector<int> A(N);
	int S=0;
	for (int i=0; i<N; i++) {
		cin >> A[i];
		string month = to_string(i+1);
		for (int j=1; j<=A[i]; j++) {
			string day = to_string(j) + month;
			if (size(set<char>(day.begin(), day.end())) == 1) {
				S++;
			}
		}
	}
	
	cout << S << '\n';
  return 0;
}
