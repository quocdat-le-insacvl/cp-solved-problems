
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define fori(n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '('; __print(x.f); cerr << "|"; __print(x.s); cerr << ')';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif


template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

void solve() {
  int n, q; cin >> n >> q;
  vpi a(n);
  vi ori(n);
  for (int i=0; i<n; i++) {
    cin >> a[i].f;
    a[i].s = i + 1;
    ori[i] = a[i].f;
  }
  // trav(x, a) cin >> x;
  // vi a(n);
  // dbg("no sort", a);
  sort(all(a));
  dbg(a);
  vi cnt(n);
  int ans = 1;
  for (int i=0; i<sz(a)-1; i++) {
    if (a[i].s > a[i+1].s){
      // f = a[i].s;
      cnt[i] = 1;
      ans++;
    }
  }
  while (q--) {
    int x,y; cin >> x >> y;
    dbg(ori);
    dbg(x,y);
    x--; y--;
    dbg(ori[x], ori[y]);
    swap(a[ori[x]-1].s, a[ori[y]-1].s);
    swap(ori[x], ori[y]);
    dbg(ori);
    dbg(a);
    // 3 2 1 4 6
    // 1 1 0 0 0
    // swap : [2], [3] (idx here: ori[x]-1, resp y)=> check [2-1]=[1], [2], [3-1]=2,[3]
    // 3 1 2 4 6
    //
    // int cnt = 1;
    // int f = a[0].s;
    int ix = ori[x]-1, iy = ori[y]-1;
    dbg(ix, iy);
    ans -= cnt[ix] + cnt[iy];
    if (ix < n - 1) cnt[ix] = a[ix].s > a[ix+1].s;
    if (iy < n - 1) cnt[iy] = a[iy].s > a[iy+1].s;
    ans += cnt[ix] + cnt[iy];
    dbg("ans1", ans);
    dbg(cnt);
    if (ix > 0) {
      ans -= cnt[ix-1];
      cnt[ix-1] = a[ix-1].s > a[ix].s;
      ans += cnt[ix-1];
    }
    if (iy > 0) {
      ans -= cnt[iy-1];
      cnt[iy-1] = a[iy-1].s > a[iy].s;
      ans += cnt[iy-1];
    }
    dbg("ans1", ans);
    dbg(cnt);
    cout << ans << '\n';

  }
}

// void solve() {
  // int n; cin >> n;
  // vi a(n); trav(x, a) cin >> x;
  // int cnt = 1;
  // for (int i=0; i<n-1; i++) {
    // if (a[i] > a[i+1]) cnt++;
  // }
  // cout << cnt << '\n';
// }

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T = 1;
  // cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}

