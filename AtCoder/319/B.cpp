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
  int a,b ; 
  //cin >> a >>  b;
  a = 24; b = 12;
  cout << a << '=' << a << ", b=" << b << '\n';
  int c = a;

  c = a;
  while ((a % c != 0) || (b % c != 0))
  {
    c--;
    cout << c << endl;
  }
  //while (c>0)
  //{
    ////if (a % c == 0 && b % c == 0)
    //if (a % c != 0 && b % c != 0)
    //{
      //c--;
    //} 
    ////else
      ////break;
    //cout << c << endl;
  //}
  //cout << c << endl;


  return 0;
}
