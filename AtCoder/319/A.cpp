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
  unordered_map<string, int> dict = {
    {"tourist", 3858},
    {"ksun48", 3679},
    {"Benq", 3658},
    {"Um_nik", 3648},
    {"apiad", 3638},
    {"Stonefeang", 3630},
    {"ecnerwala", 3613},
    {"mnbvmar", 3555},
    {"newbiedmy", 3516},
    {"semiexp", 3481},
  };
  string t;
  cin >> t;
  cout << dict[t] << '\n';



  return 0;
}
